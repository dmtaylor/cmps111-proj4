/* metacat.c: Program for printing metadata from file
 * By: Forrest Kerslager, Nick Noto, David Taylor, Kevin Yeap,
 *     Connie Yu
 * 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#DEFINE MAX_SIZE 1024


int main(int argc, char** argv){
    int fd;
    char buffer[MAX_SIZE];
    
    
    if(argc != 2){
        fprintf(stderr, "Usage: metacat FILE\n");
        exit(1);
    }
    fd = open(argv[1], O_RDWR);
    if(fd == -1){
        fprintf(stderr, "Error, file not found\n");
        exit(-1);
    }
    metaread(fd, &buffer, MAX_SIZE);
    printf("%s\n", buffer);
    return 0;   
}
