//
// Created by juan on 29/04/15.
//

#ifndef CONCURRENTES_TP1_SUPERVISORA_H
#define CONCURRENTES_TP1_SUPERVISORA_H

#include <iostream>

#include "structures/MemoriaCompartida.h"
#include "structures/LockFile.h"

#include "Proceso.h"
#include "Zappi.h"
#include "Caja.h"

class Supervisora: public Proceso {
public:
	Supervisora(int segundos);
    virtual ~Supervisora();
    void run();

private:
    void controlarCaja();
    void dormir();

    int segundos;

	MemoriaCompartida<Caja>* memoriaCompartidaCaja;
	LockFile* lockMemoriaCompartidaCaja;
};


#endif //CONCURRENTES_TP1_SUPERVISORA_H
