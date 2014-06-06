/*Demonstrate that changing the metadata does not change the regular file contents*/
#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>



int main (void)
{
	int fd;

	fd = open("testfile", O_RDWR & O_CREAT, S_IRWXU);
	if (fd == -1) { 
		printf("DEBUG: File open failed.\n");
	}
    /*buffer for regular file contents*/
    bufferReg[101] = "Regular file contents\n";
    /*write to regular file region*/
    write(fd, &bufferReg, 100);
    /*clear buffer*/
    memset(&bufferReg[0], 0, sizeof(bufferReg));
    
    /*buffer for metadata region contents*/
	char buffer[101] = "meta meta meta\n";
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
    /*clear buffer*/
    memset(&buffer[0], 0, sizeof(buffer));

    /*check that regular file contents unchanged*/
    read(fd, &bufferReg, 100);
    while(bufferReg[i] != '\0') {
        printf("%c", bufferReg[i]);
        i++;
    }
    
	printf("\n\n");

}
`