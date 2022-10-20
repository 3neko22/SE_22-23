#include "globalVariables.h"

pthread_t tidClock,tidTimer;

int tick,done;

int main (){
    tick=0;
    done=0;
    while (1){
        if(pthread_create(&tidClock,NULL,&erlojua,NULL)!=0){
            return -1;
        }
        if(pthread_create(&tidTimer,NULL,&timer,NULL)!=0){
            return -1;
        }
        
    }
        
}
