/*
 * Horno.h
 *
 *  Created on: 26/4/2015
 *      Author: mateo
 */

#ifndef HORNO_H_
#define HORNO_H_

#include "structures/FifoLectura.h"
#include "structures/FifoEscritura.h"
#include "structures/Semaforo.h"

#include "Proceso.h"
#include "Zappi.h"

class Horno: public Proceso {
public:
	Horno();
	virtual ~Horno();
	void run();

	void incrementarHornosLibres();

private:
	FifoLectura* colaPizzasHornear;
	FifoEscritura* colaPizzaHorneadas;

	Semaforo* semaforoHornosLibres;
};

#endif /* HORNO_H_ */
