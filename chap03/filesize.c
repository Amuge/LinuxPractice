#include<stdio.h>
#include<sys/stat.h>

int main()
{
    struct stat infobuf; // place to store info
    if(stat("/etc/passwd", &infobuf) == -1)
        perror("/etc/passwd");
    else
        printf("The size of /etc/passwd is %ld\n",
        infobuf.st_size);
}