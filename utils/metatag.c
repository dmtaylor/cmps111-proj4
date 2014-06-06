/* metatag.c: Program for adding metadata to a file
 * By: Forrest Kerslager, Nick Noto, David Taylor, Kevin Yeap,
 *     Connie Yu
 * 
 * 2014/06/06
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argc, char** argv){
    char* buffer;
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
    buffer = "";
    for(i=2; i<argc; i++){
        strcat(buffer, argv[i]);
        strcat(buffer, " ");
    }
    len = strlen(buffer);
    if(len > MAX_LEN-1){
        fprintf(stderr, "Input stream exceeds max length\n");
        exit(1);
    }
    metawrite(fd,&buffer,len);
    close(fd);
    return 0;
    
}
