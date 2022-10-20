#include "timer.h"

void* timer(void* arg){
    pthread_mutex_lock(&lock);
    while (1){
        tick++;
        done++;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
    }
}