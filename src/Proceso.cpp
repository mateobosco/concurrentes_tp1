/*
 * Proceso.cpp
 *
 *  Created on: 26/4/2015
 *      Author: mateo
 */

#include "Proceso.h"

Proceso::Proceso() {
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );
	this->semaforoIniciador = new Semaforo("aux/semaforoIniciador.txt",0);
}

Proceso::~Proceso() {
	Logger::log(Logger::INFO, "Finaliza el proceso");

	this->semaforoIniciador->eliminar();
	delete this->semaforoIniciador;
	SignalHandler :: destruir ();
}

void Proceso::changeName(std::string name){

	const char* new_name = name.c_str();
	prctl(PR_SET_NAME, (unsigned long) new_name, 0, 0, 0);
}
