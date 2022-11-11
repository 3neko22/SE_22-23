#include "scheduler.h"

void* scheduler_funtzioa(void* arg){
    while(1){
        if(sem_wait(&SEM_SCHED)!=0){
        printf("\nShceduler semaforoa ez du funtzionatzen\n");
         }
    printf("\nHAZ COSAS\n");
    }
   
}