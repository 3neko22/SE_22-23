#ifndef CLOCK_H
#define CLOCK_H
#include "globalVariables.h"
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
extern pthread_t tid;
void* erlojua(void* arg);
#endif