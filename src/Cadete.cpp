/*
 * Cadete.cpp
 *
 *  Created on: 28/4/2015
 *      Author: mateo
 */

#include "Cadete.h"

Cadete::Cadete() {
	this->colaPizzasHorneadas = new FifoLectura("/tmp/pizzasHorneadas");
	this->colaPizzasHorneadas->abrir();
}

Cadete::~Cadete() {
	this->colaPizzasHorneadas->cerrar();
	this->colaPizzasHorneadas->eliminar();
	delete this->colaPizzasHorneadas;
}

void Cadete::run(){
	this->changeName("TP - Cadete");
	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHorneada = new Zappi("",0);
		size_t len = sizeof(Zappi);
//		std::cout << "CADETE: Espero para leer"<<getpid() << std::endl;
		ssize_t leidos = this->colaPizzasHorneadas->leer((void*) pizzaHorneada, len);

		if(leidos == len){
			std::cout<< "CADETE : leo una pizza"<<std::endl;
		}

		delete pizzaHorneada;
	}


}

