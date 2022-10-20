#include "clock.h"

 void* erlojua(void* arg){

    if(pthread_mutex_init(&lock,NULL)!=0){
        printf("\n mutex init has failed\n");
        return ;
    }
    while(1){
        pthread_mutex_lock(&lock);
        tick=0;
        while(tick<MAIZTASUNA){
            if (pthread_cond_init(&cond,NULL)!=0){//Baldintza hari sortu errorea baldin badago orduan atera
                printf("\n condicional mutex initialitation has failed\n");
                break;
            }
            pthread_cond_wait(&cond,&lock);//tiene que esperar por lo cual se desactiva el mutex
            tick++;
        }
        tick=0;
        if(pthread_cond_init(&cond2,NULL)!=0){
            printf("\n condicional mutex initialitation has failed\n");
            break;
        }
        pthread_cond_broadcast(&cond2);
        pthread_mutex_unlock(&lock);
        break;
    }
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