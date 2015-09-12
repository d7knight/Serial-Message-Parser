/*
 * serial_adapter.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: david
 */
#include "serial_adapter.h";
using namespace std;

int current_index=0;
const char SEPARATOR = 0xFE;
const char START_BYTE = 0xFF;
const char MSG_ID_1= 0x00;//ONE PAYLOAD
const char MSG_ID_2= 0x01;//TWO PAYLOADS
const char MSG_ID_3= 0x02;//THREE PAYLOADS

const char MSG_1[25]={
		START_BYTE, START_BYTE, START_BYTE, START_BYTE,START_BYTE,
		MSG_ID_1,
		0x00,0x00,0x00,
        SEPARATOR,
		0x00,0x01,0x02,0x03,
        SEPARATOR,
		0X00,0x01,0x02,0x03,
        SEPARATOR,
		0xa2,0x9c,0x22,0x97,
        SEPARATOR
};

const int MSG_1_LENGTH=25;


int read(char *buf, unsigned int count){
    int final_index=current_index+count;
    final_index=final_index%MSG_1_LENGTH;
    int copied=0;

    for (int i = current_index; copied < count; i=(i+1)%MSG_1_LENGTH) {
		buf[copied]= MSG_1[i];
		copied++;
	}
    current_index=final_index;
	return copied;
}

void process_message(char *buffer, unsigned int message_id) {

}


int get_message_size_from_message_id(int message_id) {
	int ret=-1;
    switch(message_id){
    case MSG_ID_1:
    	ret=MSG_1_LENGTH-5;
    	break;
    }
	return ret;
}

