/*
 * Configuracion.cpp
 *
 *  Created on: 4/5/2015
 *      Author: mateo
 */

#include "Configuracion.h"

Configuracion::Configuracion(std::string archivo) {
	std::ifstream file;
	file.open(archivo.c_str());
	std::string line;
	getline(file,line);
	int d;
	sscanf( line.c_str(), "recepcionistas:%d", &d);
	this->recepcionistas = d;
	getline(file,line);
	sscanf( line.c_str(), "cocineros:%d", &d);
	this->cocineros = d;
	getline(file,line);
	sscanf( line.c_str(), "hornos:%d", &d);
	this->hornos = d;
	getline(file,line);
	sscanf( line.c_str(), "cadetes:%d", &d);
	this->cadetes = d;
	getline(file,line);
	sscanf( line.c_str(), "tiempo-supervisora:%d", &d);
	this->tiempo_supervisora = d;
	getline(file,line);
}

Configuracion::~Configuracion() {
	// TODO Auto-generated destructor stub
}

int Configuracion::getCantRecepcionistas(){
	return this->recepcionistas;
}

int Configuracion::getCantCocineros(){
	return this->cocineros;
}

int Configuracion::getCantHornos(){
	return this->hornos;
}

int Configuracion::getCantCadetes(){
	return this->cadetes;
}

int Configuracion::getTiempoSupervisora(){
	return this->tiempo_supervisora;
}
