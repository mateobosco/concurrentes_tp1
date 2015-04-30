/*
 * Cadete.h
 *
 *  Created on: 28/4/2015
 *      Author: mateo
 */

#ifndef CADETE_H_
#define CADETE_H_

#include <iostream>

#include "structures/FifoLectura.h"
//#include "structures/FifoEscritura.h"

#include "Proceso.h"
#include "Zappi.h"
#include "structures/MemoriaCompartida.h"

class Cadete: public Proceso {
public:
	Cadete();
	virtual ~Cadete();
	void run();
	void depositarEnCaja(int total);
private:
	FifoLectura* colaPizzasHorneadas;
//	FifoEscritura* colaPizzasCobrar;
};

#endif /* CADETE_H_ */
