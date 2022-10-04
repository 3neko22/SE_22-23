#include "globalVariables.h"

pthread_mutex_t lock;
pthread_t tid[2];
int main(){
    zikloa=0;
    int i=0;
    int error;
    if(phtread_mutex_init(&lock,NULL) !=0){
        printf("\n mutex init has failed\n");
        return 1;
    }
    while (i<2){
        error=pthread_create(&(tid[i]),NULL, NULL,NULL);
        if(error !=0)
            printf("\n >Thread can't be created : [%s]",strerror(error));
        i++;    
    }

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}

void* erlojua(void* arg){

    while (1){
        
    }
}