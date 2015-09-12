//
// Created by david on 12/09/15.
//

#include <boost/crc.hpp>
#include <netinet/in.h>
#include <assert.h>
#include "helper.h"
using namespace std;
int get_crc_32(const string &my_string) {
    boost::crc_32_type result;
    result.process_bytes(my_string.data(), my_string.length());
    return result.checksum();
}

uint32_t read_unsigned_int(char *buf, uint32_t size, uint32_t &value) {
    assert(size >= sizeof(uint32_t));
    value = ntohl(*(uint32_t*)buf);
    return sizeof(uint32_t);
}

uint32_t write_unsigned_int(char *buf, uint32_t size, uint32_t value) {
    assert(size >= sizeof(uint32_t));
    *(uint32_t*)buf = htonl(value);
    return sizeof(uint32_t);
}