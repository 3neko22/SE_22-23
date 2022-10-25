#include "timer.h"

void* timer(void* arg){
    pthread_mutex_lock(&lock);
    tickP=0;
    while (tickP< PERIODO_PROCESSGEN || tickS < PERIODO_SCHEDULER){
        if(tickP< PERIODO_PROCESSGEN){
            tickP++;
            printf("tick Process\n");
        }
        if(tickS< PERIODO_SCHEDULER){
            tickS++;
            printf("tick Scheduler\n");
        }
        done++;
    }
    pthread_cond_signal(&cond);
    pthread_cond_wait(&cond2,&lock);
}
