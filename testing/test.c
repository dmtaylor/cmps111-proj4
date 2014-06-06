#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

void test(void *buffer)
{
	message m;
	int fd;

	fd = open("testfile", O_RDONLY);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}

	m.m1_i1 = fd;
	m.m1_i2 = 100;
	m.m1_p1 = (char *) buffer;
    _syscall(VFS_PROC_NR, 69, &m);
}

int main (void)
{
	char buffer[101];
	int fd;

    /*	test(&buffer); */
	fd = open("testfile", O_RDWR);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    metaread(fd,&buffer,100); 

	printf("\n\n");

    metawrite(fd,&buffer,100);
}
