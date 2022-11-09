#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "process.h"
#define TENP_KOP 2

extern int SCHE_PERIOD, PROCC_PERIOD; // Scheduler eta prozesu sorkuntzaren peridoa

extern int done; //done erabiliko da jakiteko zenbat timer amaitu badute

//Bi kontagailu: scheduler-ari eta beste bat process generator
extern int tickS,tickP;
extern pthread_mutex_t lock;// lehenengo mutex-a oraindik bakarrik bat erabilita
extern pthread_t tidClock, tidTimerProcess,tidTimerScheduler;
extern pthread_cond_t cond,cond2;

extern struct PCB *ProzesuSortzailea;
extern struct ProcQueue *ProzesuIlara;
extern void hasieraketaPCB();
extern void sortuProzesua();
extern void printeatuProzesuak();
#endif