/*
 * Cocinero.h
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#ifndef COCINERO_H_
#define COCINERO_H_

#include "structures/FifoLectura.h"
#include "structures/FifoEscritura.h"
#include "structures/Semaforo.h"

#include "Proceso.h"
#include "Zappi.h"

class Cocinero: public Proceso {
public:
	Cocinero();
	virtual ~Cocinero();
	void run();
	void ocuparHorno();

private:
	FifoLectura* colaPedidosCocinar;
	FifoEscritura* colaPizzasHornear;
	Semaforo* semaforoHornosLibres;
	Semaforo* semaforoPedidosPendientes;
};

#endif /* COCINERO_H_ */
