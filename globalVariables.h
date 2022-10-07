#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
extern int tick;
const int maiztasuna=7.0;
extern pthread_mutex_t lock;
extern pthread_t tid;
extern pthread_cond_t cond,cond2;