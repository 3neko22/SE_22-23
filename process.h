#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
typedef struct {
    int PID;
} process;
typedef struct {
    ProcQueue *next;
    process *content;
} *ProcQueue;

typedef struct {
    ProcQueue *ilara;
    int HurrengoPID;
} *PCB;

struct PCB *ProzesuSortzailea;
struct ProcQueue *ProzesuIlara;
#endif