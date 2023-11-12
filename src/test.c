#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

#include "../include/wholefile.h"

int main(void) {
	uint8_t *p = NULL;
	size_t l = wholefile_stdin(&p);
	printf("len: %zu\n", l);
}
