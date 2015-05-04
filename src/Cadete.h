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
#include "structures/MemoriaCompartida.h"
#include "structures/LockFile.h"

#include "Proceso.h"
#include "Zappi.h"
#include "Caja.h"


class Cadete: public Proceso {
public:
	Cadete();
	virtual ~Cadete();
	void run();
	void depositarEnCaja(int precio);

private:
	FifoLectura* colaPizzasHorneadas;

	MemoriaCompartida<Caja>* memoriaCompartidaCaja;
	LockFile* lockMemoriaCompartidaCaja;
};

#endif /* CADETE_H_ */
