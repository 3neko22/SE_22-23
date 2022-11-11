#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <semaphore.h>
#define TENP_KOP 2
#define Prozesu_KOP 50

#define RESET_COLOR "\033[0m"
#define YELOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define GREEN "Green \033[0;32m"

extern int SCHE_PERIOD, PROCC_PERIOD; // Scheduler eta prozesu sorkuntzaren peridoa

extern int done; //done erabiliko da jakiteko zenbat timer amaitu badute

extern pthread_mutex_t lock;// lehenengo mutex-a oraindik bakarrik bat erabilita
extern pthread_t tidClock, tidTimerProcess,tidTimerScheduler,tidProcessGenerator,tidTimerScheduler;
extern pthread_cond_t cond,cond2;

extern sem_t SEM_PROC,SEM_SCHED,SEM_PRINT;

extern struct ProzesuSistema *ProzesuSortzailea;
extern void hasieraketaPCB();
extern void* sortuProzesua(void*arg);
// extern void sortuProzesua();

extern void* scheduler_funtzioa(void* arg);
#endif