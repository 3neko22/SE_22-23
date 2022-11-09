#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
struct proc {
    int PID;
};

struct ProcQueue {
    struct ProcQueue *next;
    struct proc *content;
};

struct PCB {
    struct ProcQueue *ilara;
    int HurrengoPID;
};


#endif