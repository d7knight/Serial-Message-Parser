//
// Created by david on 12/09/15.
//

#include "serial_message_parser.h"
#include <iostream>
#include <iomanip>
#include <bitset>
#include "serial_adapter.h"
#include "helper.h"



using namespace std;


int main() {
    int start_flag_counter = 0;
    int garbage_data;
    while (true) {

        char data[1];

        int ret = read_all(data, 1);
        if (!ret)continue;
        if (*data == START_BYTE) {
            start_flag_counter++;
            if (start_flag_counter == 5) {
                unsigned int message_length, message_id;
                char *message = parse_message(message_length, message_id);
                bool valid = is_valid(message, message_length);
                cout << "Received Message with ID: "<< message_id<<" "
                << (valid?" Valid Message - Processing Message": " Invalid Message - Discarding Message")<< endl;


                if (valid) {
                    process_message(message, message_length);
                }
                start_flag_counter = 0;
                delete message;
                message=NULL;
            }

        } else {
            start_flag_counter = 0;
        }

    }

    return 0;
}

bool read_all(char *buffer, int len) {
    int got_so_far = 0;
    while (got_so_far < len) {
        int nbytes = read((buffer + got_so_far), (len - got_so_far));
        if (nbytes <= 0) {

            return false;
        }
        got_so_far += nbytes;
    }
    return true;
}

char *parse_message(unsigned int &message_length, unsigned int &message_id) {

    char header[HEADER_SIZE];
    read_all(header, HEADER_SIZE);


    message_id = header[0];
    int msgSize = get_message_size_from_message_id(message_id);
    message_length = msgSize + START_FLAG_LENGTH;
    char *message = new char[message_length];

    int index = 0;
    while (index < START_FLAG_LENGTH) {
        message[index] = START_FLAG[index];
        ++index;
    }
    int header_index = 0;
    while (index < START_FLAG_LENGTH + HEADER_SIZE) {
        message[index] = header[header_index];
        ++index;
        ++header_index;
    }

    read_all(message + index, message_length - HEADER_SIZE - START_FLAG_LENGTH);
    return message;

}


bool is_valid(char *message, unsigned int message_length) {
    string data;
    char separator;
    int crc_index = message_length - CHECKSUM_SIZE;
    for (int i = START_FLAG_LENGTH; i < crc_index; ++i) {
        //Separator every 5 bytes
        if ((i > 5) && ((i + 1) % 5 == 0)) {
            separator = message[i];
            if (separator != SEPARATOR) {
                return false;
            }
        }
        else {
            char data_byte = message[i];
            data += data_byte;
        }
    }
    separator = message[message_length - 1];
    if (separator != SEPARATOR) {
        return false;
    }


    u_int32_t crc = 0;
    read_unsigned_int(message + crc_index, sizeof(uint32_t), crc);
    int computed_crc = get_crc_32(data);

     cout << " Computed CRC " << std::hex << computed_crc << " Expected CRC " <<std::hex<< crc<< endl;
    return crc == computed_crc;


}

