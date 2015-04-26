/*
 * Horno.h
 *
 *  Created on: 26/4/2015
 *      Author: mateo
 */

#ifndef HORNO_H_
#define HORNO_H_

#include "structures/FifoLectura.h"
//#include "structures/FifoEscritura.h"

#include "Proceso.h"
#include "Zappi.h"

class Horno: public Proceso {
public:
	Horno();
	virtual ~Horno();
	void run();

private:
	FifoLectura* colaPizzasHornear;
//	FifoEscritura* colaPizzasRetirar;
};

#endif /* HORNO_H_ */
