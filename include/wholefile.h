#ifndef _WHOLEFILE_WHOLEFILEH
#define _WHOLEFILE_WHOLEFILEH

#include <stdint.h>
#include <unistd.h>

size_t wholefile_read(char* path, uint8_t** buf);
ssize_t wholefile_stdin(uint8_t** buf);

#endif
