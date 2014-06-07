/*Demonstrate adding a note “This file is awesome!” to a README.txt file, and later 
reading back the note.*/

#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>


int main (void)
{
	char buffer[101] = "This file is awesome!\n";
	int fd, i = 0;

	fd = open("README.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    /*Write "this file is awesome" to metadata region*/
    metawrite(fd, &buffer, 100);
    /*Clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));
    /*Read back data from metadata region*/
    metaread(fd,&buffer,100); 
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    return 0;
}
