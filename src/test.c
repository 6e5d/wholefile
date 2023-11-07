#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

#include "../include/wholefile.h"

int main() {
	uint8_t *p = NULL;
	ssize_t l = wholefile_stdin(&p);
	printf("len: %zu\n", l);
}
