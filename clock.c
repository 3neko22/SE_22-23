#include "clock.h"

 void* erlojua(void* arg){
    while(1){
        pthread_mutex_lock(&lock);
        while (done<TENP_KOP){
            pthread_cond_wait(&cond,&lock);//tiene que esperar por lo cual se desactiva el mutex
        }
        done=0;
        pthread_cond_broadcast(&cond2);
        pthread_mutex_unlock(&lock);
    }
}
