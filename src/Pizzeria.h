/*
 * Pizzeria.h
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#ifndef PIZZERIA_H_
#define PIZZERIA_H_

#include "GeneradorLlamados.h"
#include "Recepcionista.h"

class Pizzeria {
public:
	Pizzeria();
	virtual ~Pizzeria();
	void crearGeneradorLlamados();
	void crearRecepcionistas(int n);
};

#endif /* PIZZERIA_H_ */
