/*Demonstrate that changing the metadata does not change the regular file contents*/
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
	int fd, i = 0;
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
    /*clear buffer*/
    /* Want to clear whole buffer, not the size of a pointer d.t. */
    memset(&bufferReg, 0, sizeof(char)*BUF_SIZE); 
    

    /*write metadata*/
    metawrite(fd, &buffer, BUF_SIZE-1);
    /*clear buffer*/
    /* Want to clear whole buffer, not the size of a pointer d.t. */
    memset(&buffer, 0, sizeof(char)*BUF_SIZE);
    /*confirm metadata written*/
    metaread(fd,&buffer,BUF_SIZE-1);
    printf("%s\n", buffer);
    
    /* Not sure if the following code is necessary*/
    /*while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }*/
    i = 0;
    /*clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));

    /*check that regular file contents unchanged*/
    read(fd, &bufferReg, BUF_SIZE-1);
    
    printf("%s\n", bufferReg);

    /*while(bufferReg[i] != '\0') {
        printf("%c", bufferReg[i]);
        i++;
    }*/
    i = 0;
	printf("\n\n");

}
