/*
 * Zappi.h
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#ifndef ZAPPI_H_
#define ZAPPI_H_

#include <iostream>

class Zappi {
public:
	Zappi(std::string gusto, int duracion);
	virtual ~Zappi();

	std::string getGusto();
	int getDuracion();

private:
	std::string gusto;
	int duracion;
};

#endif /* ZAPPI_H_ */
