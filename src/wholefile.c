#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../include/wholefile.h"

#define PosixStat stat
#define PosixSsizeT ssize_t
#define o_rdonly O_RDONLY
#define stdin_fileno STDIN_FILENO

size_t wholefile(read)(char* path, uint8_t** buf) {
	int fd = open(path, o_rdonly);
	struct PosixStat st;
	fstat(fd, &st);
	size_t len = (size_t)st.st_size;
	*buf = malloc(len + 1);
	if(*buf == NULL) {abort();}
	if (read(fd, *buf, len) != (PosixSsizeT)len) {
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
		PosixSsizeT s = read(stdin_fileno, *buf, cap - len);
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
