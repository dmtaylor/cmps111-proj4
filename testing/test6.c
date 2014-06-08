/*Demonstrate that changing the metadata on the original file does not modify the 
metadata of the copied file*/
/*First run test2.c to create original*/
/*Then run test5.sh*/


#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define BUF_SIZE 101

int main (void)
{
	char buffer[BUF_SIZE] = "NEW STUFF IN ORIGINAL\n";
    char bufferCOPY[BUF_SIZE] = "\n";
	int fd, fd2, i = 0;

	fd = open("README.txt", O_RDWR | O_CREAT, S_IRWXU);
    fd2 = open("copy.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    if (fd2 == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    
    /*Write "NEW STUFF IN ORIGINAL" to metadata region of original README.txt*/
    metawrite(fd, &buffer, BUF_SIZE-1);
    /*Clear buffer*/
    /* Same changes as in 4 & 5 */
    memset(&buffer, 0, sizeof(char)*BUF_SIZE);
    /*Read back data from metadata region of README.txt*/
    metaread(fd,&buffer,BUF_SIZE-1); 
    
    printf("%s\n", buffer);
    /*
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    */
    
    /* same change */
    memset(&bufferCOPY, 0, sizeof(char)*BUF_SIZE);
    /*check metadata in copy.txt to make sure it's the same*/ 
    metaread(fd2,&bufferCOPY,BUF_SIZE-1);
    printf("%s\n", bufferCOPY);
    
    /*while(bufferCOPY[i] != '\0') {
        printf("%c", bufferCOPY[i]);
        i++;
    }*/
    return 0;
}
