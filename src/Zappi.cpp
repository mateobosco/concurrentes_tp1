/*
 * Zappi.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "Zappi.h"

Zappi::Zappi(std::string gusto, int duracion) {
	this->gusto = gusto;
	this->duracion = duracion;
}

Zappi::~Zappi() {
}

int Zappi::getDuracion() {
	return this->duracion;
}

std::string Zappi::getGusto() {
	return this->gusto;
}

