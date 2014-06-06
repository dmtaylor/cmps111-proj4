/* metatag.c: Program for adding metadata to a file
 * By: Forrest Kerslager, Nick Noto, David Taylor, Kevin Yeap,
 *     Connie Yu
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    metawrite(fd,&buffer,len);
    return 0;
    
}
