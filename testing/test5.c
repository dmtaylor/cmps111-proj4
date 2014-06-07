/*Demonstrate that copying a file with metadata copies the metadata*/
/*This file just reads the metadata from the new copied file "copy.txt" and prints it out */
#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>



int main (void)
{
	char buffer[101] = "\n";
	int fd, i = 0;

	fd = open("copy.txt", O_RDWR & O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}

    /*Clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));
    /*Read back data from metadata region*/
    metaread(fd,&buffer,100); 
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    i = 0;
    
    
    return 0;
}