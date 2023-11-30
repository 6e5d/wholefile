#include <unistd.h>

#include "../include/wholefile.h"

int main(void) {
	uint8_t *p = NULL;
	size_t l = wholefile_stdin(&p);
	printf("len: %zu\n", l);
}
