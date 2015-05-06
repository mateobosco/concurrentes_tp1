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

	this->semaforoHornosLibres = new Semaforo("aux/semaforoHornosLibres.txt");
	this->incrementarHornosLibres();
}

Horno::~Horno() {

	this->colaPizzasHornear->cerrar();
	this->colaPizzasHornear->eliminar();
	delete this->colaPizzasHornear;

	this->colaPizzaHorneadas->cerrar();
	this->colaPizzaHorneadas->eliminar();
	delete this->colaPizzaHorneadas;

	this->semaforoHornosLibres->eliminar();
	delete this->semaforoHornosLibres;
}

void Horno::run(){
	this->changeName("TP - Horno");

	this->semaforoIniciador->p();

	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHornear = new Zappi("",0,0);
		size_t len = sizeof(Zappi);
		std::cout << "HORNO: Espero para leer"<<getpid() << std::endl;
		ssize_t leidos = this->colaPizzasHornear->leer((void*) pizzaHornear, len);

		if(leidos == (ssize_t) len){
			std::cout<< "HORNO : leo una pizza"<<std::endl;
			Logger::log(Logger::INFO,"Meto al horno una Pizza de " + pizzaHornear->getGusto() );
			this->semaforoHornosLibres->v(); // decrementa
//			this->ocuparHorno();
			pizzaHornear->cocinarse();
			ssize_t escritos = this->colaPizzaHorneadas->escribir((void*) pizzaHornear, len);
			if(escritos != len){
				Logger::log(Logger::ERROR," Se escribio mal la Pizza  " + pizzaHornear->getGusto() );
			}
			Logger::log(Logger::INFO,"Se cocino la Pizza de " + pizzaHornear->getGusto() );
			this->incrementarHornosLibres(); // incrementa
		}
		else{
			Logger::log(Logger::ERROR," Se leyo  mal la Pizza  " );
		}
		delete pizzaHornear;
	}
}

void Horno::incrementarHornosLibres(){
	this->semaforoHornosLibres->v();
}
