#include "globalVariables.h"
#include "clock.h"
#include "timer.h"
pthread_t tidClock,tidTimer;

pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

int tick,done;

int main (){
    tick=0;
    done=0;
    while (1){
        if(pthread_create(&tidClock,NULL,&erlojua,NULL)!=0){
            return -1;
        }
        if(pthread_create(&tidTimer,NULL,&timer,NULL)!=0){
            return -1;
        }
        
    }
        
}
