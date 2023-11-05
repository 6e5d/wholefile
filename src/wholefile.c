#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>

size_t wholefile_read(char* path, uint8_t** buf) {
	int fd = open(path, O_RDONLY);
	struct stat st;
	fstat(fd, &st);
	size_t len = (size_t)st.st_size;
	*buf = malloc(len);
	assert(read(fd, *buf, len) == len);
	assert(close(fd) == 0);
	return len;
}
