#ifndef INCLUDEGUARD_WHOLEFILE_WHOLEFILEH
#define INCLUDEGUARD_WHOLEFILE_WHOLEFILEH

#include <stdint.h>
#include <unistd.h>

size_t wholefile_read(char* path, uint8_t** buf);
size_t wholefile_stdin(uint8_t** buf);

#endif
