#include "timer.h"

void* timerScheduler(void* arg){
    tickS=0;
    pthread_mutex_lock(&lock);
    while (1){
        done++;
        tickS++;
        if (tickS>=SCHE_PERIOD)
        {
            //sem_post(SEM_SCHED);
            tickS=0;
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
            sem_post(SEM_PROC);
            printf("\nENTRA\n");
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
        //printf("\nSeñal pasatu Process\n");
    }
    
}
