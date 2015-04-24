/*
 * Recepcionista.h
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#ifndef RECEPCIONISTA_H_
#define RECEPCIONISTA_H_

#include "structures/FifoLectura.h"
#include "Zappi.h"

class Recepcionista {
public:
	Recepcionista();
	virtual ~Recepcionista();
	void run();

private:
	FifoLectura* colaPedidosRecibir;
};

#endif /* RECEPCIONISTA_H_ */
