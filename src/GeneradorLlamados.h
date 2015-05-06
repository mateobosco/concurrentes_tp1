/*
 * GeneradorLlamados.h
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#ifndef GENERADORLLAMADOS_H_
#define GENERADORLLAMADOS_H_

#include <iostream>
#include <vector>

#include "structures/FifoEscritura.h"
#include "structures/Semaforo.h"

#include "Proceso.h"
#include "Zappi.h"
#include "ZappiFactory.h"


class GeneradorLlamados: public Proceso {
public:
	GeneradorLlamados();
	virtual ~GeneradorLlamados();
	void run();

private:
	int seg;
	FifoEscritura* fifoLlamadosGenerados;
	Semaforo* semaforoPizzeriaGracefulQuit;
};

#endif /* GENERADORLLAMADOS_H_ */
