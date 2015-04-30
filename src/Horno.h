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
#include "structures/MemoriaCompartida.h"
#include "structures/LockFile.h"

#include "Proceso.h"
#include "Zappi.h"

class Horno: public Proceso {
public:
	Horno();
	virtual ~Horno();
	void run();

	void liberarHorno();
	void ocuparHorno();

private:
	FifoLectura* colaPizzasHornear;
	FifoEscritura* colaPizzaHorneadas;

	MemoriaCompartida<int>* cantHornosLibres;
	LockFile* lockHornosOcupados;
};

#endif /* HORNO_H_ */
