#include<lib.h>
#include<unistd.h>
#include<stdio.h>

PUBLIC int metaread(void)
{
    message m;

	printf("POSIX: debug: metaread has been called.\n");

    return(_syscall(VFS_PROC_NR, 0, &m));
}
