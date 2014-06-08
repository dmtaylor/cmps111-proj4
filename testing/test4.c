/*Demonstrate that changing the metadata does not change the regular file contents*/
/*Should display "meta meta meta" as the altered metadata content, followed by 
"Regular file contents", which means the regular file contents weren't changed */
#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#define BUF_SIZE 101

int main (void)
{
	int fd;
    /*buffer for regular file contents*/
    char bufferReg[BUF_SIZE] = "Regular file contents\n";
    /*buffer for metadata region contents*/
	char buffer[BUF_SIZE] = "meta meta meta\n";
    
	fd = open("testfile.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}

    /*write to regular file region*/
    write(fd, &bufferReg, BUF_SIZE-1);
    sync();
    /*clear buffer*/
    /* Want to clear whole buffer, not the size of a pointer d.t. */
    memset(&bufferReg, 0, sizeof(char)*BUF_SIZE); 
    close(fd);
    fd = open("testfile.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    /*write metadata*/
    metawrite(fd, &buffer, BUF_SIZE-1);
    sync();
    /*clear buffer*/
    /* Want to clear whole buffer, not the size of a pointer d.t. */
    memset(&buffer, 0, sizeof(char)*BUF_SIZE);
    /*confirm metadata written*/
    metaread(fd,&buffer,BUF_SIZE-1);
    printf("%s\n", buffer);

    /*clear buffer*/
    memset(&buffer, 0, sizeof(char)*BUF_SIZE);
    close(fd);
    fd = open("testfile.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    /*check that regular file contents unchanged*/
    read(fd, &bufferReg, BUF_SIZE-1);
    close(fd);
    printf("%s\n", bufferReg);

	printf("\n\n");

}
