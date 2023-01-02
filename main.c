#include "globalVariables.h"
#include "clock.h"
#include "timer.h"

//Posfix hariak
struct haria tidClock,tidTimerProcess,tidTimerScheduler,tidProcessGenerator,tidScheduler;

//Conda mutex eta mutex lock deklaratzeko
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

//Semaforoen deklarazioa
sem_t SEM_PROC,SEM_SCHED,EZABAKETA;

//Prozesu ilara gordeko duen 
struct ProzesuSistema *ProzesuSortzailea;

//Erlojuaren kontsumituta dauden baliabideen kopurua gordeko du
int done;

// Scheduler-a eta Prozesu Sortzailearen periodoak gordeko ditu
int SCHE_PERIOD,PROCC_PERIOD;

int SCHE_MOTA;

//Programa nagusia
int main (int argc, char *argv[]){
    //Balioak defektuz
    SCHE_PERIOD=4000;
    PROCC_PERIOD=30000;
    //Exekuzio komandoaren formaren aukerak analizatzeko erabiliko da
    int opt;
    char* scheduler_mota;
    while ((opt=getopt(argc,argv,":s:p:m:"))!=-1){
        switch(opt){
            case 's'://scheduler
                SCHE_PERIOD=atoi(optarg);
                break;
            case 'p'://process generator
                PROCC_PERIOD=atoi(optarg);
                break;
            case 'm':
                if(strcmp(optarg,"fifo")==0){
                    printf("\nFIFO eginda\n");
                }
                else if(strcmp(optarg,"cosa")==0){
                    printf("\nBeste mota sartuta\n");
                }
            case ':'://"campo" batean ez bada jartzen baliorik, adibiez, -s [hutsa] -p 40
                printf("\n"RED"Ez duzu sartu baliorik"RESET_COLOR"\n");
                break;
            case '?'://adibidez: ./Programa -- sartzerakoan
                printf("\nDEFAULT BALIOAK SARTUTA\n");
        }
        
    }
    //Aukeratutako balioak pantailaratu
    printf("\n"GREEN"Scheduler-aren periodoa"RESET_COLOR" %d\n",SCHE_PERIOD);
    printf("\n"GREEN" Process-aren peridoa"RESET_COLOR" %d \n",PROCC_PERIOD);

    //Hasieraketak
    if (pthread_cond_init(&cond,NULL)!=0){
        printf("\n "RED"\"conda\" Baldintza mutex-a errore bat izan du"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_cond_init(&cond2,NULL)!=0){
        printf("\n "RED"\"conda\" Baldintza mutex-a errore bat izan du"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_mutex_init(&lock,NULL)!=0){
        printf("\n"RED"Lock mutex-a"RESET_COLOR"\n");
        return -1;
    }
    if(sem_init(&SEM_PROC,0,0)!=0){
        printf("\n"RED"Prozesu Semaforoa errore bat izan du"RESET_COLOR"\n");
        return -1;
    }
    if(sem_init(&SEM_SCHED,0,0)!=0){
        printf("\n"RED"Scheduler Semaforoa errore bat izan du"RESET_COLOR"\n");
        return -1;
    }
    hasieraketaPCB();
    done=0;

    /*
        EXEKUZIO-KODEA
    */

    //Hariak sortu
    tidTimerProcess.scheduler_o_process=1;
    tidTimerScheduler.scheduler_o_process=0;
    tidScheduler.scheduler_mota=0;

    if(pthread_create(&tidClock.thread,NULL,&erlojua,NULL)!=0){
        printf("\n"RED"Hari erlojua izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_create(&tidTimerProcess.thread,NULL,&timer,&tidTimerProcess.scheduler_o_process)!=0){
        printf("\n"RED"Hari Timer-Process izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_create(&tidTimerScheduler.thread,NULL,&timer,&tidTimerScheduler.scheduler_o_process)!=0){
        printf("\n"RED"Hari Timer-Scheduler izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_create(&tidProcessGenerator.thread,NULL,&sortuProzesua,NULL)!=0){
        printf("\n"RED"Hari prozesuSortzailea izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_create(&tidScheduler.thread,NULL,&scheduler_funtzioa,&tidScheduler.scheduler_mota)!=0){
        printf("\n"RED"Hari Scheduler izan du errorea"RESET_COLOR"\n");
        return -1;
    }

    //Hariak amaitu direla sahiestu
    if(pthread_join(tidTimerProcess.thread,NULL)!=0){
        printf("\n"RED"Hari Timer-Process izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_join(tidTimerScheduler.thread,NULL)!=0){
        printf("\n"RED"Hari Timer-Scheduler izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_join(tidProcessGenerator.thread,NULL)!=0){
        printf("\n"RED"Hari prozesuSortzailea izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_join(tidScheduler.thread,NULL)!=0){
        printf("\n"RED"Hari Scheduler izan du errorea"RESET_COLOR"\n");
        return -1;
    }
    if(pthread_join(tidClock.thread,NULL)!=0){
        printf("\n"RED"Hari erlojua izan du errorea"RESET_COLOR"\n");
        return -1;
    }
}

