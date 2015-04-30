/*
 * Zappi.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "Zappi.h"

Zappi::Zappi(std::string gusto, int duracion, int precio) {
	memcpy(this->gusto,gusto.c_str(),gusto.size());
	this->duracion = duracion;
	this->precio = 50;
}

Zappi::~Zappi() {
}

int Zappi::getDuracion() {
	return this->duracion;
}

std::string Zappi::getGusto() {
	return this->gusto;
}

int Zappi::getPrecio() {
	return this->precio;
}


