#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#define MAIZTASUNA 100000
/**
 * done erabiliko da timer-a periodo iristen denean eta erlojura bueltatuko da
 * tick erabiliko da 
*/
extern int tick,done; 
extern pthread_mutex_t lock;// lehenengo mutex-a oraindik bakarrik bat erabilita
extern pthread_t tidClock, tidTimer;
extern pthread_cond_t cond,cond2;
#endif