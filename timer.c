#include "timer.h"

void* timer(void* arg){
    pthread_mutex_lock(&lock);
    while (1){
        if(tickP >=PERIODO_PROCESSGEN){
            tickP=0;
            printf("tick Process\n");
        }
        if(tickS >=PERIODO_SCHEDULER){
            tickS=0;
            printf("tick Scheduler\n");
        } 
        tickP++;
        tickS++;
        done++;
    }

    pthread_cond_signal(&cond);
    pthread_cond_wait(&cond2,&lock);
}
