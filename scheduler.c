#include "scheduler.h"


void* lehenengo_prozesua_ezabatu(){
    // ProzesuSortzailea->ilara
    for(int i=0; i<ProzesuSortzailea->hurrengoPID;i++){
        if(ProzesuSortzailea->ilara[i]->state==0){
            ProzesuSortzailea->ilara[i]->state=1;
            break;
        }
    }

}

void* scheduler_funtzioa(void* arg){
    //Oraindik ez du ezer egingo, bakarrik zerbait egiten duela
    if((int*) arg==0){
        printf("\n"GREEN"FIFO"RESET_COLOR"\n");
    }
    while(1){
        if(sem_wait(&SEM_SCHED)!=0){
            printf("\n"RED"Shceduler semaforoa ez du funtzionatzen"RESET_COLOR"\n");
        }
        lehenengo_prozesua_ezabatu();
    }
    
}