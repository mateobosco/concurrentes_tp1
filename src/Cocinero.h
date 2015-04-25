/*
 * Cocinero.h
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#ifndef COCINERO_H_
#define COCINERO_H_

#include "structures/FifoLectura.h"

#include "Zappi.h"

class Cocinero {
public:
	Cocinero();
	virtual ~Cocinero();
	void run();

private:
	FifoLectura* colaPedidosCocinar;
};

#endif /* COCINERO_H_ */
