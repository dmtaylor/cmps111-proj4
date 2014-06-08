/*Demonstrate that creating 1000 files, adding metadata to them, then deleting them does
 not decrease the free space on the filesystem.*/
#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <string.h>


int main (void)
{
	char buffer[101] = "lulz\n";
	int fd, i = 0;
    char filename[1010];
    for (i = 1; i < 1001; i++) {
        sprintf(filename, "%d", i);
        fd = open(filename, O_RDWR | O_CREAT, S_IRWXU);
        if (fd == -1) { 
            printf("DEBUG: File open failed.\n");
        }  
        /*Write "lulz" to metadata region*/
        metawrite(fd, &buffer, 100);
        sync();
        close(fd);
        remove(filename);
    }
    return 0;
}
