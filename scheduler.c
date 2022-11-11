#include "scheduler.h"

void* scheduler_funtzioa(void* arg){
    //Oraindik ez du ezer egingo, bakarrik zerbait egiten duela
    while(1){
        if(sem_wait(&SEM_SCHED)!=0){
            printf("\n"RED"Shceduler semaforoa ez du funtzionatzen"RESET_COLOR"\n");
        }
    }
}