/* metatag.c: Program for adding metadata to a file
 * By: Forrest Kerslager, Nick Noto, David Taylor, Kevin Yeap,
 *     Connie Yu
 * 
 * 2014/06/06
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LEN 1024

int main(int argc, char** argv){
    char buffer[MAX_LEN];
    int fd, i, len;
    
    if(argc < 3){
        fprintf(stderr, "Usage: metatag FILE TAG\n");
        exit(1);
    }
    fd=open(argv[1], O_RDWR);
    if(fd == -1){
        fprintf(stderr, "Error, file not found\n");
        exit(1);
    }

    for(i=2; i<argc; i++){
		len = strlen(buffer) + strlen(argv[i]) + 1;
		if(len > MAX_LEN-1){
			fprintf(stderr, "Input stream exceeds max length\n");
			exit(1);
		}
        strcat(buffer, argv[i]);
        strcat(buffer, " ");
    }

    metawrite(fd,&buffer,len);
    close(fd);
    return 0;
    
}
