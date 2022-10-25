#include "globalVariables.h"
#include "clock.h"
#include "timer.h"
pthread_t tidClock,tidTimer,tidTimer2;

pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

int done;

int tickP,tickS;

//Programa nagusia
int main (){
    
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
        if(pthread_create(&tidClock,NULL,&erlojua,NULL)!=0){
            return -1;
        }
        if(pthread_create(&tidTimer,NULL,&timer,NULL)!=0){
            return -1;
        }
        if(pthread_create(&tidTimer2,NULL,&timer,NULL)!=0){
            return -1;
        }
    }
        
}
