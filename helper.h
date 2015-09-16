//
// Created by david on 12/09/15.
//

#ifndef HELPER_H
#define HELPER_H
#include <string>

int get_crc_32(const std::string &my_string);
uint32_t read_unsigned_int(char *buf, uint32_t size, uint32_t &value);
uint32_t write_unsigned_int(char *buf, uint32_t size, uint32_t value);

#endif //HELPER_H
