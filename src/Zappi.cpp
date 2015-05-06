/*
 * Zappi.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "Zappi.h"

Zappi::Zappi(){
	this->duracion = 0;
	this->precio = 0;
}

Zappi::Zappi(std::string gusto, int duracion, int precio) {
	memset(this->gusto,0,50);
	memcpy(this->gusto,gusto.c_str(),gusto.size());
	this->duracion = duracion;
	this->precio = precio;
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

void Zappi::cocinarse(){

}
