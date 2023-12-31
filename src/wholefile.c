#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../include/wholefile.h"

size_t wholefile(read)(char* path, uint8_t** buf) {
	int fd = open(path, O_RDONLY);
	struct stat st;
	fstat(fd, &st);
	size_t len = (size_t)st.st_size;
	*buf = malloc(len + 1);
	if(*buf == NULL) {abort();}
	if (read(fd, *buf, len) != (ssize_t)len) {
		fprintf(stderr, "read %s failed\n", path);
		abort();
	}
	*(*buf + len) = '\0';
	if(close(fd) != 0) {abort();}
	return len;
}

size_t wholefile(stdin)(uint8_t** buf) {
	if(*buf != NULL) {abort();}
	size_t cap = 65536;
	size_t len = 0;
	while(1) {
		*buf = realloc(*buf, cap);
		if(*buf == NULL) {abort();}
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
	if(*buf == NULL) {abort();}
	return len;
}
#undef wholefile
