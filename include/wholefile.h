#ifndef INCLUDEGUARD_WHOLEFILE
#define INCLUDEGUARD_WHOLEFILE
#define NS_NAME(symbol) com_6e5d_wholefile_##symbol

size_t NS_NAME(read)(char* path, uint8_t** buf);
size_t NS_NAME(stdin)(uint8_t** buf);

#undef NS_NAME
#endif
