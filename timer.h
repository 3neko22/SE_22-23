#ifndef TIMER_H
#define TIMER_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
extern pthread_t tidTimerProcess,tidTimerScheduler;

void* timerScheduler(void *arg);
void* timerProcess(void *arg);
#endif