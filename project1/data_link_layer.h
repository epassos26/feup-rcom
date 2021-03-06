#ifndef DATA_LINK_LAYER_H
#define DATA_LINK_LAYER_H

#define FLAG 0x7E
#define ESCAPE 0x7D
#define STUFFING_BYTE 0x20

#define SEND 0x03
#define RECEIVE 0x01

#define SET 0x03
#define UA 0x07
#define DISC 0x0B
#define RR 0x05
#define REJ 0x01

#define COM1 0
#define COM2 1
#define COM1_PORT "/dev/ttyS0"
#define COM2_PORT "/dev/ttyS1"

#define US_FRAME_LENGTH 5
#define I_FRAME_HEADER_SIZE 6

#define DATA_PACKET_BYTE 1
#define START_PACKET_BYTE 2
#define END_PACKET_BYTE 3

typedef enum { TRANSMITTER, RECEIVER } status;

/**
* Opens the terminal refered to by terminal.
* Updates the port settings and saves the old ones to be reset.
* Depending on status, it send a SET or UA frame.
* Returns the according file descriptor on success,
* returning -1 otherwise.
*/
int llopen(int port, status stat);

/**
* Writes the given msg with len length to the
* given fd.
* Returns -1 on error.
*/
int llwrite(int fd, char *msg, int len);

/**
* Reads the message from fd and places it on
* msg, updating len accordingly.
* Returns -1 on error.
*/
int llread(int fd, char *msg, int *packet_len);

/**
* Closes the given fd and sets the port settings.
* Returns -1 on error.
*/
int llclose(int fd);

/**
* Closes the given fd and resets the port settings.
* Should be used when there is a problem with the connection.
*/
void force_close(int fd);

/**
* Initialize data_link struct variables.
*/
void init_data_link(int time_out,int number_retries, int baudrate);

/**
* Get the number of timeouts at the end.
*/
int getTotalTimeouts();

#endif
