#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
struct PCB {
    int PID;
    struct PCB *next;
};

struct ProzesuSistema {
    struct PCB** ilara;
    int hurrengoPID;
};


#endif