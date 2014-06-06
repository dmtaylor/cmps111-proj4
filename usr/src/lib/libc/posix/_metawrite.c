#include <lib.h>
#include <unistd.h>
#include<stdio.h>

PUBLIC ssize_t metawrite(fd, buffer, nbytes)
int fd;
void *buffer;
size_t nbytes;
{
    message m;

	printf("POSIX: debug: metawrite has been called.\n");

	m.m1_i1 = fd;
	m.m1_i2 = nbytes;
	m.m1_p1 = (char *) buffer;
    return(_syscall(VFS_PROC_NR, 70, &m));
}
