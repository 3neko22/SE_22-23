#include "globalVariables.h"
#include "clock.h"
#include "timer.h"
pthread_t tidClock,tidTimerProcess,tidTimerScheduler;

pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

int done;

int tickP,tickS;

int SCHE_PERIOD,PROCC_PERIOD;
//Programa nagusia
int main (int argc, char *argv[]){
    SCHE_PERIOD=40000;
    PROCC_PERIOD=30000;
    int opt;
    while ((opt=getopt(argc,argv,":s:p:"))!=-1){
        switch(opt){
            case 's'://scheduler
                SCHE_PERIOD=atoi(optarg);
                break;
            case 'p'://process generator
                PROCC_PERIOD=atoi(optarg);
                break;
            case ':':// por ejemplo poner -s sin asignarle valor
                printf("\nEz duzu sartu baliorik\n");
                break;
            case '?':
                printf("\nDefault balioak sartuta \n");
        }
        
    }
    printf("\n Scheduler-aren periodoa %d\n",SCHE_PERIOD);
    printf("\n Process-aren peridoa %d \n",PROCC_PERIOD);
    //Hasieraketak
    done=0;
    tickP=0;tickS=0;
    if (pthread_cond_init(&cond,NULL)!=0){//Baldintza hari sortu errorea baldin badago orduan atera
        printf("\n condicional mutex initialitation has failed\n");
        return -1;
    }
    if(pthread_cond_init(&cond2,NULL)!=0){
        printf("\n condicional mutex initialitation has failed\n");
        return -1;
    }
    

    //Exekuzio-kodea
    
    while (1){
        if(pthread_mutex_init(&lock,NULL)!=0){
            printf("\n mutex init has failed\n");
            return -1;
        }
        if(pthread_create(&tidClock,NULL,&erlojua,NULL)!=0){
            return -1;
        }
        if(pthread_create(&tidTimerProcess,NULL,&timerProcess,NULL)!=0){
            return -1;
        }
        if(pthread_create(&tidTimerScheduler,NULL,&timerScheduler,NULL)!=0){
            return -1;
        }
    }
        
}
