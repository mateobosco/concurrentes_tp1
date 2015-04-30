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

	this->lockHornosOcupados = new LockFile("lockHornosOcupados.txt");
	this->cantHornosLibres = new MemoriaCompartida<int>();
	this->cantHornosLibres->crear("cantHornosLibres.txt",'R');
	this->liberarHorno();
}

Horno::~Horno() {
	this->ocuparHorno();

	this->colaPizzasHornear->cerrar();
	this->colaPizzasHornear->eliminar();
	delete this->colaPizzasHornear;

	this->colaPizzaHorneadas->cerrar();
	this->colaPizzaHorneadas->eliminar();
	delete this->colaPizzaHorneadas;

//	delete this->lockHornosOcupados;
	this->cantHornosLibres->liberar();
	delete this->cantHornosLibres;
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
			this->ocuparHorno();
			pizzaHornear->cocinarse();
			this->colaPizzaHorneadas->escribir((void*) pizzaHornear, len);
			this->liberarHorno();
		}
		delete pizzaHornear;
	}
}

void Horno::ocuparHorno(){
	int hornos = this->cantHornosLibres->leer();
	hornos --;
	this->cantHornosLibres->escribir(hornos);
	if (hornos == 0){
		this->lockHornosOcupados->tomarLock();
	}
}

void Horno::liberarHorno(){
	int hornos = this->cantHornosLibres->leer();
	hornos ++;
	this->cantHornosLibres->escribir(hornos);
	if (hornos == 1){
		this->lockHornosOcupados->liberarLock();
	}
}
