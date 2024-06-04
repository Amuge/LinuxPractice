#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

void show_info(struct utmp *);

int main()
{
    struct utmp current_record;
    int utmp_fd;
    int rec_len = sizeof(current_record);

    if ((utmp_fd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);
        exit(1);
    }

    while (read(utmp_fd, &current_record, rec_len) == rec_len)
        show_info(&current_record);

    close(utmp_fd);
    return 0;
}

void show_info(struct utmp *utbufp)
{
    printf("%-8.8s", utbufp->ut_user); // user name
    printf(" ");
    printf("%-8.8s", utbufp->ut_line); // device name
    printf(" ");
    printf("%10ld", utbufp->ut_time);
    printf(" ");

#ifdef SHOWHOST
    printf("%s", utbufp->ut_host);
#endif
    printf("\n");
}