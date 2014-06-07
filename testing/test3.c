/*Demonstrate that changing the regular file contents does not change the extra 
metadata. Should print "Don't Change" if successful*/
#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>


int main (void)
{
    /*buffer for metadata region contents*/
	char buffer[101] = "Don't change\n";
    /*buffer for regular file contents*/
    char bufferReg[101] = "Regular file contents\n";
	int fd, i = 0;

	fd = open("testfile.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    /*write metadata*/
    metawrite(fd, &buffer, 100);
    /*clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));
    /*confirm metadata written*/
    metaread(fd,&buffer,100); 
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    i = 0;
    /*clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));

    /*write to regular file region*/
    write(fd, &bufferReg, 100);
    /*clear buffer*/
    memset(&bufferReg[0], 0, sizeof(bufferReg));
    /*confirm regular file contents written*/
    read(fd, &bufferReg, 100);
    while(bufferReg[i] != '\0') {
        printf("%c", bufferReg[i]);
        i++;
    }
    i = 0;
    /*Check if metadata region still unchanged*/
    read(fd, &buffer, 100);
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    return 0;
}
