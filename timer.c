#include "timer.h"

void* timer(void* arg){
    pthread_mutex_lock(&lock);
    while (1){
        done++;
        //printf("DONE %d\n",done);
        if(done > PERIODO){
            done=0;
            printf("done %d\n", done);
            pthread_cond_signal(&cond);
        }
        pthread_cond_wait(&cond2,&lock);
    }
}