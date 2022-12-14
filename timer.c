#include "timer.h"
// Timer zenbat denbora iraun behar du scheduler-ari eta prozesu sortzaileari señal bat bidaltzeko
int tick;

//Scheduler timer-aren funtzioa
void* timer(void* arg){
    tick=0;
    //Mutex lock-a blokeatzen du 
    pthread_mutex_lock(&lock);

    //Scheduler
    if(((int *)arg)==0){
        while (1){
            done++;
            tick++;
            if (tick>=SCHE_PERIOD)
            {
                //seinalea bidaltzen dio scheduler-ari
                if(sem_post(&SEM_SCHED)!=0){
                    printf("\n"RED"NO funciona la señal schduler"RESET_COLOR"\n");
                }
                tick=0;   
            }
            pthread_cond_signal(&cond);
            //Itxaron cond2 bidaltzen badu seinalea 
            pthread_cond_wait(&cond2,&lock);
        }
    }
    else{
        //Process Generator
        while (1){
            done++;
            tick++;
            if (tick>=PROCC_PERIOD)
            {
                //seinalea bidaltzen dio scheduler-ari
                if(sem_post(&SEM_PROC)!=0){
                    printf("\n"RED"NO funciona la señal schduler"RESET_COLOR"\n");
                }
                tick=0;   
            }
            pthread_cond_signal(&cond);
            //Itxaron cond2 bidaltzen badu seinalea 
            pthread_cond_wait(&cond2,&lock);
        }
    }
   
}
