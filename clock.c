#include "clock.h"

 void* erlojua(void* arg){
    while(1){
        //mutex-a blokeatu
        pthread_mutex_lock(&lock);
        while (done<TENP_KOP){
            pthread_cond_wait(&cond,&lock);//itxaron egingo du
        }
        done=0;
        pthread_cond_broadcast(&cond2);
        pthread_mutex_unlock(&lock);
    }
}
