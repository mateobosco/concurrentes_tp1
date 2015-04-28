/*
 * Pizzeria.h
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#ifndef PIZZERIA_H_
#define PIZZERIA_H_

#include <stdlib.h>
#include <vector>

#include "Proceso.h"
#include "GeneradorLlamados.h"
#include "Recepcionista.h"
#include "Cocinero.h"
#include "Horno.h"

class Pizzeria: public Proceso {
public:
	Pizzeria();
	virtual ~Pizzeria();
	void crearGeneradorLlamados();
	void crearRecepcionistas(int n);
	void crearCocineros(int n);
	void crearHornos(int n);

	void run();

private:
	std::vector<int> childs;
};

#endif /* PIZZERIA_H_ */
