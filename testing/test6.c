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

int main (void)
{
	char buffer[101] = "NEW STUFF IN ORIGINAL\n";
    char bufferCOPY[101] = "\n";
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
    metawrite(fd, &buffer, 100);
    /*Clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));
    /*Read back data from metadata region of README.txt*/
    metaread(fd,&buffer,100); 
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    memset(&bufferCOPY[0], 0, sizeof(buffer));
    /*check metadata in copy.txt to make sure it's the same*/ 
    metaread(fd2,&buffer,100); 
    while(bufferCOPY[i] != '\0') {
        printf("%c", bufferCOPY[i]);
        i++;
    }
    return 0;
}
