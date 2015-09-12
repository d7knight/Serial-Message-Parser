/*
 * serial_adapter.h
 *
 *  Created on: Sep 11, 2015
 *      Author: david
 */

#ifndef SERIAL_ADAPTER_H_
#define SERIAL_ADAPTER_H_


/** 
 * Attempts to read up to count number of bytes from the serial 
 * port into the buffer starting at ​buf​. 
 *  
 * Returns the number of bytes actually read. 
 */
int read(char *buf, unsigned int count);
/** 
 * This function should only be called when a complete message 
 * has been parsed. The complete message should be at the start 
 * of the input buffer. 
 */
void process_message(char *buffer, unsigned int message_id);


/** 
 * Returns the size (in bytes) of the message with the specified 
 * message_id. The message size includes the separator bytes 
 * (0xFE) and the checksum but does not include the start flag. 
 */
int get_message_size_from_message_id(int message_id);

#endif /* SERIAL_ADAPTER_H_ */
