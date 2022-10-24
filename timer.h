#ifndef TIMER_H
#define TIMER_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
#define PERIODO 50000
extern pthread_t tidTimer;
void* timer(void *arg);
#endif