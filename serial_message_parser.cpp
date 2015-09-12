#include <iostream>
#include <exception>
#include <vector>
#include <boost/crc.hpp>      // for boost::crc_basic, boost::augmented_crc
#include "serial_adapter.h"
#include "helper.h"

#include <cassert>
#include <netinet/in.h>

namespace {
    const char SEPARATOR = 0xFE;
    const char START_BYTE = 0xFF;
    const int RESERVED_SIZE = 3;
    const int HEADER_SIZE = 5;
    const int PAYLOAD_SIZE = 4;
    const int CHECKSUM_SIZE = 5;
    const int SEPERATOR_SIZE = 1;
    const int MAX_MESSAGE_SIZE = 100;
    const int START_FLAG_LENGTH = 5;
    const char START_FLAG[] = {START_BYTE, START_BYTE, START_BYTE, START_BYTE,
                               START_BYTE};
}

using namespace std;

bool read_all(char *buffer, int len);

char *parse_message(unsigned int &message_length, unsigned int &message_id,string & result_string);

bool is_valid(char *message, unsigned int message_length);

int get_crc_32(const string &my_string);

int main() {
    int counter = 0;

    while (true) {

        char data[1];
        int ret = read_all(data, 1);
        if (!ret)continue;
        if (*data == START_BYTE) {
            counter++;
            if (counter == 5) {
                unsigned int message_length, message_id;
                string result_string;
                char *message = parse_message(message_length, message_id,result_string);
                bool valid = is_valid(message, message_length);
                if (valid)
                    process_message(message, message_length);
                counter = 0;
            }

        } else {
            counter = 0;
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

char *parse_message(unsigned int &message_length, unsigned int &message_id, string &result_string) {

    char header[HEADER_SIZE];
    int ret = read_all(header, HEADER_SIZE);
    assert(ret);

    message_id = header[0];
    int msgSize = get_message_size_from_message_id(message_id);
    message_length = msgSize + START_FLAG_LENGTH;
    char *message = new char[message_length];

    int index = 0;
    while (index < START_FLAG_LENGTH) {
        message[index] = START_FLAG[index];
        ++index;
    }
    int header_index=0;
    while (index < START_FLAG_LENGTH + HEADER_SIZE) {
        message[index] = header[header_index];
        ++index;
        ++header_index;
    }

    ret = read_all(message + index, message_length - HEADER_SIZE - START_FLAG_LENGTH);
    assert(ret);
    result_string=message;
    return message;

}


bool is_valid(char *message, unsigned int message_length) {
    string data;
    char separator;
    int crc_index = message_length - CHECKSUM_SIZE;
    for (int i = START_FLAG_LENGTH; i < crc_index; ++i) {
        //Separator every 5 bytes
        if ((i > 5) && ((i+1) % 5 == 0)) {
            separator = message[i];
            if (separator != SEPARATOR) {
                return false;
            }
        }
        else {
            char data_byte=message[i];
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
    assert(crc != computed_crc);
    if (crc != computed_crc)
        return true;
    else
        return false;

}

