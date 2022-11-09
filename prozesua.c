#include "process.h"

void hasieraketaPCB(){
    ProzesuSortzailea=(struct PCB*) malloc(sizeof(struct PCB));
    ProzesuIlara=(struct ProcQueue*) malloc(sizeof(struct ProcQueue));
    ProzesuSortzailea->ilara=ProzesuIlara;
    ProzesuSortzailea->HurrengoPID=0;
}

void sortuProzesua(){
    struct proc *prozesua=(struct proc*) malloc(sizeof(struct proc));
    prozesua->PID=ProzesuSortzailea->HurrengoPID;
    ProzesuSortzailea->HurrengoPID+=1;
    if(ProzesuIlara->content==NULL){
        ProzesuIlara->content=prozesua;
        printf("\nhola %d\n", ProzesuIlara->content->PID);

    }
    else{
        struct ProcQueue *laguntzaile=(struct ProcQueue*) malloc(sizeof(struct ProcQueue));
        laguntzaile=ProzesuIlara;
        while(laguntzaile->next!=NULL){
            laguntzaile=laguntzaile->next;
        }
        laguntzaile->next->content=prozesua;
        free(laguntzaile);
    }  
}

void printeatuProzesuak(){
    struct ProcQueue *laguntzaile=(struct ProcQueue*) malloc(sizeof(struct ProcQueue));
    laguntzaile=ProzesuIlara;
    while(laguntzaile->next!=NULL){
        printf("\nProzesua - PID: %d\n",laguntzaile->content->PID);
        laguntzaile=laguntzaile->next;
    }
    free(laguntzaile);
}

