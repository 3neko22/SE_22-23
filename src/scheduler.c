#include "../include/scheduler.h"


void* lehenengo_prozesua_ezabatu(){
    // ProzesuSortzailea->ilara
    for(int i=0; i<ProzesuSortzailea->elem_kop-1;i++){
        if(ProzesuSortzailea->ilara[i]->state==0){
            ProzesuSortzailea->ilara[i]->state=1;
            break; 
        }
    }
}
  

void* scheduler_funtzioa(void* arg){
    //Oraindik ez du ezer egingo, bakarrik zerbait egiten duela
    if(tidScheduler.scheduler_mota==0){
        printf("\n"GREEN"FIFO"RESET_COLOR"\n");
        while(1){
            if(sem_wait(&SEM_SCHED)!=0){
                printf("\n"RED"Shceduler semaforoa ez du funtzionatzen"RESET_COLOR"\n");
            }
            lehenengo_prozesua_ezabatu();
        }
    }
    else{
        while(1){
            if(sem_wait(&SEM_SCHED)!=0){
                printf("\n"RED"Shceduler semaforoa ez du funtzionatzen"RESET_COLOR"\n");
            }
        }
    }
    
    
}