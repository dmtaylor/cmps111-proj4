/*Demonstrate that copying a file with metadata copies the metadata*/
/*This file just reads the metadata from the new copied file "copy.txt" and prints it out */
/*Run test2.c first to generate README.txt to be copied.*/
/*Run test5.sh to copy README.txt*/
/*Run this file to verify copy.txt still holds metadata*/
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
	char buffer[BUF_SIZE] = "\n";
	int fd, i = 0;

	fd = open("copy.txt", O_RDWR & O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}

    /*Clear buffer*/
    /* Changed mem arithmetic. buffer is a pointer d.t.*/
    memset(&buffer, 0, sizeof(char)* BUF_SIZE);
    /*Read back data from metadata region*/
    metaread(fd,&buffer, BUF_SIZE-1);
    
    /* This should be equivalent d.t.*/
    printf("%s\n", buffer);
    /*
    while(buffer[i] != '\0') {
        printf("%c", buffer[i]);
        i++;
    }
    i = 0;
    */
    
    return 0;
}
