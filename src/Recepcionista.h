/*
 * Recepcionista.h
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#ifndef RECEPCIONISTA_H_
#define RECEPCIONISTA_H_

#include "structures/FifoLectura.h"
#include "structures/FifoEscritura.h"

#include "Proceso.h"
#include "Zappi.h"

class Recepcionista: public Proceso {
public:
	Recepcionista();
	virtual ~Recepcionista();
	void run();

private:
	FifoLectura* colaPedidosRecibir;
	FifoEscritura* colaPedidosCocinar;
};

#endif /* RECEPCIONISTA_H_ */
