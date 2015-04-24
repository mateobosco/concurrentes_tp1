/*
 * GeneradorLlamados.h
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#ifndef GENERADORLLAMADOS_H_
#define GENERADORLLAMADOS_H_

#include <iostream>

#include "structures/FifoEscritura.h"
#include "Zappi.h"

class GeneradorLlamados {
public:
	GeneradorLlamados();
	virtual ~GeneradorLlamados();
	void run();

private:
	int seg;
	FifoEscritura* fifoLlamadosGenerados;

};

#endif /* GENERADORLLAMADOS_H_ */
