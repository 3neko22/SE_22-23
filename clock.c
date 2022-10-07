#include "globalVariables.h"

int tick;
void* erlojua(void* arg){
    unsigned long i=0;
    tick+=1;
    printf("\n Hasiera : %d\n",tick);
    for(i=0; i< maiztasuna; i++){
        ;
    }
    printf("\n Amaiera: %d\n", tick);

    return NULL;

}

int main(){

    if(pthread_mutex_init(&lock,NULL)!=0){
        printf("\n mutex init has failed\n");
        return -1;
    }
    while(1){
        pthread_mutex_lock(&lock);
        tick=0;
        while(tick<maiztasuna){
            if (pthread_cond_init(&cond,NULL)!=0){
                printf("\n condicional mutex initialitation has failed\n");
                return -1;
            }
            pthread_cond_wait(&cond,&lock);//tiene que esperar por lo cual se desactiva el mutex
        }
        tick=0;
        if(pthread_cond_init(&cond2,NULL)!=0){
            printf("\n condicional mutex initialitation has failed\n");
            return -1;
        }
        pthread_cond_broadcast(&cond2);
        pthread_mutex_unlock(&lock);
    }
    return 1;
}

//  int i=0;
    
//     int error;
//     if(pthread_mutex_init(&lock,NULL) !=0){
//         printf("\n mutex init has failed\n");
//         return 1;
//     }
//     while (i<2){
//         error=pthread_create(&tid,NULL,erlojua,NULL);
//         if(error !=0)
//             printf("\n >Thread can't be created : [%s]",strerror(error));
//         i++;    
//     }

//     pthread_join(tid,NULL);
//     pthread_mutex_destroy(&lock);

//     return 0;