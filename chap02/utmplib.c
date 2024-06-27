#include "utmplib.h"

int utmp_open(char *filename)
{
    fd_utmp = open(filename, O_RDONLY);
    cur_rec = num_recs = 0;
    return fd_utmp;
}

int utmp_reload()
{
    /* 
        read next bunch of records into buffer 
    */
   int amt_read;
   amt_read = read(fd_utmp, utmpbuf, NRECS * UTSIZE);
   num_recs = amt_read / UTSIZE;
   cur_rec = 0;
   return num_recs;
}

struct utmp* utmp_next()
{
    struct utmp * recp;
    if(fd_utmp == -1)
        return NULLUT;
    if(cur_rec == num_recs && utmp_reload() == 0)
        return NULLUT;
    //get address of next record
    recp = (struct utmp*)&utmpbuf[cur_rec*UTSIZE];
    cur_rec++;
    return recp;
}

void utmp_close()
{
    if(fd_utmp != -1)
        close(fd_utmp);
}