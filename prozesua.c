#include "process.h"
struct ProcQueue *ProzesuIlara;
struct PCB *ProzesuSortzailea;
void* sortuProzesua(void *arg){
    
    process *prozesua=(process*) malloc(sizeof(process));
    prozesua->PID=ProzesuSortzailea->HurrengoPID;
    ProzesuSortzailea->HurrengoPID+=1;
    if(ProzesuIlara->content==NULL){
        ProzesuIlara->content=prozesua;
    }
    else{
        ProcQueue *laguntzaile=(ProcQueue*) malloc(sizeof(ProcQueue));
        laguntzaile=ProzesuIlara;
        while(laguntzaile->next!=NULL){
            laguntzaile=laguntzaile->next;
        }
        laguntzaile->next=prozesua;
        free(laguntzaile);
    }
    
}

void hasieraketaPCB(){
    ProzesuSortzailea=(PCB*) malloc(sizeof(PCB));
    ProzesuIlara=(ProcQueue*) malloc(sizeof(ProcQueue));
    ProzesuIlara->content=NULL;
    ProzesuIlara->next=NULL;
    ProzesuSortzailea->ilara=ProzesuIlara;
    ProzesuSortzailea->HurrengoPID=0;
}