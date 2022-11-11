#include "timer.h"
// Timer zenbat denbora iraun behar du scheduler-ari eta prozesu sortzaileari señal bat bidaltzeko
int tickS,tickP;

//Scheduler timer-aren funtzioa
void* timerScheduler(void* arg){
    tickS=0;
    pthread_mutex_lock(&lock);
    while (1){
        done++;
        tickS++;
        if (tickS>=SCHE_PERIOD)
        {
            if(sem_post(&SEM_SCHED)!=0){
                printf("\n"RED"NO funciona la señal schduler"RESET_COLOR"\n");
            }
            tickS=0;   
        }
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
    }
   
}

//Prozesu Sortzaile timer-aren funtzioa
void* timerProcess(void *arg){
    tickP=0;
    //Mutex-a blokeatu
    pthread_mutex_lock(&lock);
    while(1){
        //Erloju baliabidea konsumitu duela esango du
        done++;
        tickP++;
        if(tickP >=PROCC_PERIOD){
            tickP=0;
            //Prozesu sortzailearen haria seinale bat bidali prozesu bat sortzeko
            if(sem_post(&SEM_PROC)!=0){
                printf("\n"RED"NO FUNCIONA el post timer"RESET_COLOR"\n");
            }
        }
        
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond2,&lock);
    }
    
}
