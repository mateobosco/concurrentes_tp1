/*
 * Horno.cpp
 *
 *  Created on: 26/4/2015
 *      Author: mateo
 */

#include "Horno.h"

Horno::Horno() {
	this->colaPizzasHornear = new FifoLectura("/tmp/pizzasHornear");
	this->colaPizzasHornear->abrir();

	this->colaPizzaHorneadas = new FifoEscritura("/tmp/pizzasHorneadas");
	this->colaPizzaHorneadas->abrir();
}

Horno::~Horno() {
	this->colaPizzasHornear->cerrar();
	this->colaPizzasHornear->eliminar();
	delete this->colaPizzasHornear;

	this->colaPizzaHorneadas->cerrar();
	this->colaPizzaHorneadas->eliminar();
	delete this->colaPizzaHorneadas;
}

void Horno::run(){
	this->changeName("TP - Horno");
	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHornear = new Zappi("",0);
		size_t len = sizeof(Zappi);
		std::cout << "HORNO: Espero para leer"<<getpid() << std::endl;
		ssize_t leidos = this->colaPizzasHornear->leer((void*) pizzaHornear, len);

		if(leidos == len){
			std::cout<< "HORNO : leo una pizza"<<std::endl;
	//			pizzaHornear->cocinar();
			this->colaPizzaHorneadas->escribir((void*) pizzaHornear, len);
		}
		delete pizzaHornear;
	}
}
