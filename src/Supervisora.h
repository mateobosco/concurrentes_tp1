//
// Created by juan on 29/04/15.
//

#ifndef CONCURRENTES_TP1_SUPERVISORA_H
#define CONCURRENTES_TP1_SUPERVISORA_H

#include <iostream>

#include "Proceso.h"
#include "Zappi.h"

class Supervisora: public Proceso {
    Supervisora();
    virtual ~Supervisora();
    void run();

};


#endif //CONCURRENTES_TP1_SUPERVISORA_H
