#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

size_t wholefile_read(char* path, uint8_t** buf) {
	int fd = open(path, O_RDONLY);
	struct stat st;
	fstat(fd, &st);
	size_t len = (size_t)st.st_size;
	*buf = malloc(len + 1);
	assert(*buf != NULL);
	assert(read(fd, *buf, len) == len);
	*(*buf + len) = '\0';
	assert(close(fd) == 0);
	return len;
}

size_t wholefile_stdin(uint8_t** buf) {
	assert(*buf == NULL);
	size_t cap = 65536;
	size_t len = 0;
	while(1) {
		*buf = realloc(*buf, cap);
		assert(*buf != NULL);
		ssize_t s = read(STDIN_FILENO, *buf, cap - len);
		if (s == -1) {
			printf("stdin read fail!\n");
			exit(1);
		}
		if (s == 0) {
			break;
		}
		len += (size_t)s;
		if (cap < len * 2) {
			cap *= 2;
		}
	}
	*buf = realloc(*buf, len + 1);
	*(*buf + len) = '\0';
	assert(*buf != NULL);
	return len;
}
