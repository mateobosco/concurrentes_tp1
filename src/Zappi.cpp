/*
 * Zappi.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "Zappi.h"

Zappi::Zappi(){
	this->tiempoHorno = 0;
	this->precio = 0;
	this->tiempoDistribucion = 0;
	this->tiempoPreparacion = 0;
}

Zappi::Zappi(std::string gusto, int duracion, int precio) {
	memset(this->gusto,0,50);
	memcpy(this->gusto,gusto.c_str(),gusto.size());
	this->tiempoHorno = duracion;
	this->precio = precio;
	this->tiempoPreparacion = 3;
	this->tiempoDistribucion = 4;
}

Zappi::~Zappi() {
}

std::string Zappi::getGusto() {
	return this->gusto;
}

int Zappi::getPrecio() {
	return this->precio;
}

void Zappi::cocinarse(){
	sleep(this->tiempoHorno);
}

void Zappi::preparar(){
	sleep(this->tiempoPreparacion);
}

void Zappi::repartir(){
	sleep(this->tiempoDistribucion);
}
