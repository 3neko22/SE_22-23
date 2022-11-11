#include "timer.h"

int tickS,tickP;
void* timerScheduler(void* arg){
    tickS=0;
    pthread_mutex_lock(&lock);
    while (1){
        done++;
        tickS++;
        if (tickS>=SCHE_PERIOD)
        {
            if(sem_post(&SEM_SCHED)!=0){
                printf("\nNO funciona la señal schduler\n");
            }
            tickS=0;
            printf("\nSCHEDULER\n");   
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
        
        //printf("\nSeñal pasatu Scheduler\n");
    }
   
}

void* timerProcess(void *arg){
    tickP=0;
    pthread_mutex_lock(&lock);
    while(1){
        done++;
        tickP++;
        if(tickP >=PROCC_PERIOD){
            tickP=0;
            if(sem_post(&SEM_PROC)!=0){
                printf("\nNO FUNCIONA el post timer\n");
            }
            printf("\nLLEGAS AQUI\n");
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
        
        //printf("\nSeñal pasatu Process\n");
    }
    
}
