#include "process.h"

void hasieraketaPCB(){
    ProzesuSortzailea=(struct ProzesuSistema*) malloc(sizeof(struct ProzesuSistema));
    ProzesuSortzailea->ilara=(struct PCB**)malloc(sizeof(struct PCB) * Prozesu_KOP);
    ProzesuSortzailea->hurrengoPID=0;
}

void *printeatuProzesuak(){
    
    printf("\n PROZESU SORTUTA\n");
    printf("\n-----------------\n");
    int muga=ProzesuSortzailea->hurrengoPID;
    for(int i=0;i<muga;i++){
        printf("\nProzesua - PID: %d\n",ProzesuSortzailea->ilara[i]->PID);
    }       
}

void* sortuProzesua(void *arg){
    while(1){
        if(sem_wait(&SEM_PROC)!=0){
            printf("\nSemforoa ez du funtzionatzen\n");
        }
        struct PCB *prozesua=(struct PCB*) malloc(sizeof(struct PCB));
        prozesua->PID=ProzesuSortzailea->hurrengoPID;
        if(ProzesuSortzailea->hurrengoPID==Prozesu_KOP){
            printf("\nProzesu kopuru maximora iritsita\n");
        }
        else{
            int posizioa=ProzesuSortzailea->hurrengoPID;
            ProzesuSortzailea->ilara[posizioa]=prozesua;
            if(posizioa>0){
                ProzesuSortzailea->ilara[posizioa-1]->next=prozesua;
            }
            ProzesuSortzailea->hurrengoPID+=1;
        }
        printeatuProzesuak();
    }
    
}



