#include "timer.h"

void* timerScheduler(void* arg){
    tickS=0;
    pthread_mutex_lock(&lock);
    while (1){
        done++;
        while (tickS<=SCHE_PERIOD)
        {
            tickS++;
        }
        tickS=0;
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
        while(tickP <=PROCC_PERIOD){
            tickP=0;
            //printf("tick Process\n");
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
        //printf("\nSeñal pasatu Process\n");
    }
    
}
