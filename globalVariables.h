#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define MAIZTASUNA 100000
extern int tick,done;
extern pthread_mutex_t lock;
extern pthread_t tidClock, tidTimer;
extern pthread_cond_t cond,cond2;
extern void* erlojua(void* arg);
extern void* timer(void* arg);
#endif