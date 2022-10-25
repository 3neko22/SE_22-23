#ifndef TIMER_H
#define TIMER_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
#define PERIODO_SCHEDULER 40000
#define PERIODO_PROCESSGEN 50000
extern pthread_t tidTimer,tidTimer2;
void* timer(void *arg);
#endif