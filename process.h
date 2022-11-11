#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "globalVariables.h"
struct PCB {
    int PID;//Uneko prozesuaren identifikazio zenbakia
    struct PCB *next;// hurrengo prozesuaren erakuslea gordeko du
};

struct ProzesuSistema {
    struct PCB** ilara;// array bat non gordeko dira PCB-aren prozesuen erakusleak
    int hurrengoPID;// Atzituko den hurrengo prozesuaren PID gordeko du
};
#endif