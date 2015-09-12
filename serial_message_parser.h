//
// Created by dave on 12/09/15.
//

#ifndef SKYLADDERS_SERIAL_MESSAGE_PARSER_H
#define SKYLADDERS_SERIAL_MESSAGE_PARSER_H
#include <string>
const char SEPARATOR = 0xFE;
const char START_BYTE = 0xFF;
const int HEADER_SIZE = 5;
const int CHECKSUM_SIZE = 5;
const int START_FLAG_LENGTH = 5;
const char START_FLAG[] = {START_BYTE, START_BYTE, START_BYTE, START_BYTE,
                           START_BYTE};

//Blocking Call - Reads from the serial adapter until exactly len bytes has been read
bool read_all(char *buffer, int len);

//Parse Message, Allocates Heap memory for the message buffer
char *parse_message(unsigned int &message_length, unsigned int &message_id);

//Checks if a message is valid, if the formatting of the message (Separator positioning) and the checksum are correct
bool is_valid(char *message, unsigned int message_length);

#endif //SKYLADDERS_SERIAL_MESSAGE_PARSER_H
