#include "globalVariables.h"

pthread_mutex_t lock;
pthread_t tid[2];

int zikloa;
void* erlojua(void* arg){
    unsigned long i=0;
    zikloa+=1;
    printf("\n Hasiera : %d\n",zikloa);
    for(i=0; i< (0xFFFFFFFF); i++){
        ;
    }
    printf("\n Amaiera: %d\n", zikloa);

    return NULL;

}

int main(){
    int i=0;
    int error;
    if(pthread_mutex_init(&lock,NULL) !=0){
        printf("\n mutex init has failed\n");
        return 1;
    }
    while (i<2){
        error=pthread_create(&(tid[i]),NULL,erlojua,NULL);
        if(error !=0)
            printf("\n >Thread can't be created : [%s]",strerror(error));
        i++;    
    }

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}

