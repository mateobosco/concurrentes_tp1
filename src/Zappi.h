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


class Zappi {
public:
	Zappi(std::string gusto, int duracion, int precio);
	virtual ~Zappi();

	std::string getGusto();
	int getDuracion();
	int getPrecio();

private:
	char gusto[50];
	int duracion;
	int precio;
};

#endif /* ZAPPI_H_ */
