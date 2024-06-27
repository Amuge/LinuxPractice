#pragma once
#include<stdio.h> 
#include<fcntl.h>
#include<sys/types.h>
#include<utmp.h>

#define NRECS 16
#define NULLUT ((struct utmp*)NULL)
#define UTSIZE (sizeof(struct utmp))

static char utmpbuf[NRECS*UTSIZE];// storage
static int num_recs;// num stored
static int cur_rec;// next to go
static int fd_utmp = -1;// read from

int utmp_open(char *filename);
int utmp_reload();
struct utmp* utmp_next();
void utmp_close();