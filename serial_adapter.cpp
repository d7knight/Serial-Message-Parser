/*
 * serial_adapter.cpp -My Implementation for testing purposes
 *
 *  Created on: Sep 11, 2015
 *      Author: david
 */
#include <iostream>
#include "serial_adapter.h";
using namespace std;
int current_index = 0;
const char SEPARATOR = 0xFE;
const char START_BYTE = 0xFF;
const char MSG_ID_1 = 0x01;

const char MSG_ID_2 = 0x02;

const char MSG_ID_3 = 0x03;

//The message data that read() loops over
const char MESSAGES[] = {
        //message 1
        START_BYTE, START_BYTE, START_BYTE, START_BYTE, START_BYTE,
        MSG_ID_1,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0X00, 0x01, 0x02, 0x03,
        SEPARATOR,
        0x03, 0x75, 0x86, 0xF8,
        //037586F8
        SEPARATOR,

        //invalid message 1
        START_BYTE, START_BYTE, START_BYTE, START_BYTE, START_BYTE,
        MSG_ID_1,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0X00, 0x01, 0x02, 0x06,
        SEPARATOR,
        0x03, 0x75, 0x86, 0xF8,
        //037586F8
        SEPARATOR,

        //Garbage Data
        START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE,START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE,START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,

        //message 2
        START_BYTE, START_BYTE, START_BYTE, START_BYTE, START_BYTE,
        MSG_ID_2,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0x00, 0x01, 0x02, 0x03,
        SEPARATOR,
        0X00, 0x01, 0x02, 0x03,
        SEPARATOR,
        0x91, 0x0c, 0xd1, 0x90,
        //910CD190
        SEPARATOR,

        //invalid message 2
        START_BYTE, START_BYTE, START_BYTE, START_BYTE, START_BYTE,
        MSG_ID_2,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0x00, 0x01, 0x99, 0x03,
        SEPARATOR,
        0X00, 0x01, 0x02, 0x03,
        SEPARATOR,
        0x91, 0x0c, 0xd1, 0x90,
        //910CD190
        SEPARATOR,

       //Garbage Data
        START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE,START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,

        //message 3
        START_BYTE, START_BYTE, START_BYTE, START_BYTE, START_BYTE,
        MSG_ID_3,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        SEPARATOR,
        0X00, 0x01, 0x02, 0xdd,
        SEPARATOR,
        0X00, 0xff, 0x02, 0xcc,
        SEPARATOR,
        0xff, 0xff, 0x02, 0xcc,
        SEPARATOR,
        0Xdd, 0xdd, 0x02, 0x03,
        SEPARATOR,
        0X00, 0x01, 0xdd, 0x03,
        SEPARATOR,
        0xd7, 0x4a, 0xa0, 0xa4,
        //d74aa0a4
        SEPARATOR,

        //invalid message 3
        START_BYTE, START_BYTE, START_BYTE, START_BYTE, START_BYTE,
        MSG_ID_3,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        SEPARATOR,
        0X00, 0x01, 0x02, 0xdd,
        SEPARATOR,
        0X00, 0xf9, 0x02, 0xcc,
        SEPARATOR,
        0xff, 0xff, 0x02, 0xcc,
        SEPARATOR,
        0Xdd, 0xdd, 0x02, 0x03,
        SEPARATOR,
        0X00, 0x01, 0xdd, 0x03,
        SEPARATOR,
        0xd7, 0x4a, 0xa0, 0xa4,
        //d74aa0a4
        SEPARATOR,

        //Garbage Data
        START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE,START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa,
        START_BYTE,START_BYTE, START_BYTE, START_BYTE,
        0x00, 0x00, 0x00,
        SEPARATOR,
        0xad, 0xdf, 0x02, 0xaa


};
const int MESSAGES_LENGTH = 295;

int read(char *buf, unsigned int count) {
    int final_index = current_index + count;
    final_index = final_index % MESSAGES_LENGTH;
    int copied = 0;

    for (int i = current_index; copied < count; i = (i + 1) % MESSAGES_LENGTH) {
        buf[copied] = MESSAGES[i];
        copied++;
    }
    current_index = final_index;
    return copied;
}
//note: caller is responsible for freeing the buffer
void process_message(char *buffer, unsigned int message_id) {


}


int get_message_size_from_message_id(int message_id) {
    int ret = -1;
    switch (message_id) {
        case MSG_ID_1:
            ret = 15;
            break;
        case MSG_ID_2:
            ret = 20;
            break;
        case MSG_ID_3:
            ret = 40;
            break;
    }
    return ret;
}

