#include "globalVariables.h"

int main(){
    pthread_mutex_lock(&lock);
    while (1){
        tick++;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
    }
}