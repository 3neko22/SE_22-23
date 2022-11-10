#include "process.h"

void hasieraketaPCB(){
    ProzesuSortzailea=(struct ProzesuSistema*) malloc(sizeof(struct ProzesuSistema));
    ProzesuSortzailea->ilara=(struct PCB**)malloc(sizeof(struct PCB) * Prozesu_KOP);
    ProzesuSortzailea->hurrengoPID=0;
}

void sortuProzesua(){
    sem_wait(SEM_PROC);
    struct PCB *prozesua=(struct PCB*) malloc(sizeof(struct PCB));
    prozesua->PID=ProzesuSortzailea->hurrengoPID;
    if(ProzesuSortzailea->hurrengoPID==Prozesu_KOP){
        printf("\nProzesu kopuru maximoan iritsita\n");
    }
    else{
        printf("\nENTRA\n");
        int posizioa=ProzesuSortzailea->hurrengoPID;
        ProzesuSortzailea->ilara[posizioa]=prozesua;
        if(posizioa>0){
            ProzesuSortzailea->ilara[posizioa-1]->next=prozesua;
        }
        ProzesuSortzailea->hurrengoPID+=1;
    }
    
}

void printeatuProzesuak(){
    printf("\n PROZESU SORTUTA\n");
    printf("\n-----------------\n");
    int muga=ProzesuSortzailea->hurrengoPID;
    for(int i=0;i<muga;i++){
        printf("\nProzesua - PID: %d\n",ProzesuSortzailea->ilara[i]->PID);
    }        
}

