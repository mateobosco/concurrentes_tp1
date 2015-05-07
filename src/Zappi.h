/*
 * Zappi.h
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#ifndef ZAPPI_H_
#define ZAPPI_H_

#include <iostream>
#include <string.h>
#include <unistd.h>


class Zappi {
public:
	Zappi();
	Zappi(std::string gusto, int duracion, int precio);
	virtual ~Zappi();

	std::string getGusto();
	int getTiempoHorno();
	int getPrecio();
	void cocinarse();
	void repartir();
	void preparar();

private:
	char gusto[100];
	int tiempoHorno;
	int precio;
	int tiempoPreparacion;
	int tiempoDistribucion;
};

#endif /* ZAPPI_H_ */
