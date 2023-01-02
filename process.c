#include "process.h"

//Egitura globalaren hasieraketak
void hasieraketaPCB(){
    ProzesuSortzailea=(struct ProzesuSistema*) malloc(sizeof(struct ProzesuSistema));
    ProzesuSortzailea->ilara=(struct PCB**)malloc(sizeof(struct PCB) * Prozesu_KOP);
    ProzesuSortzailea->hurrengoPID=0;
}

//Sortuta dauden prozesuak sortuta
void *printeatuProzesuak(){
    printf("\n PROZESU SORTUTA\n");
    printf("\n-----------------\n");
    int muga=ProzesuSortzailea->hurrengoPID;
    for(int i=0;i<muga;i++){
        printf("\n"BLUE"Prozesua - PID:"RESET_COLOR""YELOW" %d"BLUE"-State:"YELOW" %d"RESET_COLOR"\n",ProzesuSortzailea->ilara[i]->PID,ProzesuSortzailea->ilara[i]->state);
    }     
}
//Prozesu berri bat sortuko duen funtzioa
void* sortuProzesua(void *arg){
    while(1){
        //Geldi egongo da timer-a seinale bat iritsi arte
        if(sem_wait(&SEM_PROC)!=0){
            printf("\nSemforoa ez du funtzionatzen\n");
        }
        //Prozesu berri bat memorian atzitu
        struct PCB *prozesua=(struct PCB*) malloc(sizeof(struct PCB));
        prozesua->PID=ProzesuSortzailea->hurrengoPID;//Izando duen identifikazio zenbakia
        //Ilararen kopuru maximora iristen bada ez sartu prozesu berririk
        if(ProzesuSortzailea->hurrengoPID==Prozesu_KOP){
            printf("\n"RED"Prozesu kopuru maximora iritsita"RESET_COLOR"\n");
        }
        else{
            //Azken posizioa hartu
            int posizioa=ProzesuSortzailea->hurrengoPID;
            //Ilaran gorde
            ProzesuSortzailea->ilara[posizioa]=prozesua;
            //Azkenaurreko prozesuarekin lotu PCB-an
            if(posizioa>0){
                ProzesuSortzailea->ilara[posizioa-1]->next=prozesua;
            }
            ProzesuSortzailea->hurrengoPID+=1;//Eguneratu 
        }
        printeatuProzesuak();
    }
    
}



