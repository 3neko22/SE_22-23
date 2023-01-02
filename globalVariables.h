#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <semaphore.h>
#define TENP_KOP 2
#define Prozesu_KOP 500

#define RESET_COLOR "\033[0m"
#define YELOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
extern int SCHE_PERIOD, PROCC_PERIOD; // Scheduler eta prozesu sorkuntzaren peridoa

extern int done; //done erabiliko da jakiteko zenbat timer amaitu badute

// lehenengo mutex-a oraindik bakarrik bat erabilita
extern pthread_mutex_t lock;
//6 hari sortuta, bata erlojuarentzat, timer bakoitzak beste bat, prozesu sortzailearentzat beste bat eta seigarrena scheduler-a.
//extern pthread_t tidClock, tidTimerProcess,tidTimerScheduler,tidProcessGenerator;
//Bi baldintza mutex-a
extern pthread_cond_t cond,cond2;
extern struct ProzesuSistema *ProzesuSortzailea;

//Semaforoak, bata prozesu sortzailearentzat eta bestea scheduler-arentzat
extern sem_t SEM_PROC,SEM_SCHED,EZABAKETA;


/*
    Egiturak
*/

struct haria{
    pthread_t thread;
    int scheduler_o_process;
    int scheduler_mota;// Shceduler-aren mota erabakitzeko
};





// PCB kudeaketan beharrezkoak diren hasieraketak eta memoria atzipenak egingo du
extern void hasieraketaPCB();
//prozesu berri bat sortu eta PCB-n eta Queue-n lotu egingo du
extern void* sortuProzesua(void*arg);

//Oraingoz ez du ezer egiten
extern void* scheduler_funtzioa(void* arg);
#endif