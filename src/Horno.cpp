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

	this->semaforoCadetesLibres = new Semaforo("aux/semaforoCadetesLibres.txt");
}

Horno::~Horno() {
	Logger::Instance()->log(Logger::INFO, "Finaliza el proceso");

	this->colaPizzasHornear->cerrar();
	this->colaPizzasHornear->eliminar();
	delete this->colaPizzasHornear;

	this->colaPizzaHorneadas->cerrar();
	this->colaPizzaHorneadas->eliminar();
	delete this->colaPizzaHorneadas;

	this->semaforoHornosLibres->eliminar();
	delete this->semaforoHornosLibres;

	this->semaforoCadetesLibres->eliminar();
	delete this->semaforoCadetesLibres;
}

void Horno::run(){
	this->changeName("TP - Horno");

	this->semaforoIniciador->p();

	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHornear = new Zappi();
		size_t len = sizeof(Zappi);
		ssize_t leidos = this->colaPizzasHornear->leer((void*) pizzaHornear, len);

		if(leidos == (ssize_t) len){
			Logger::Instance()->log(Logger::INFO,"Meto al horno una Pizza de " + pizzaHornear->getGusto() );

			this->semaforoHornosLibres->v();
			pizzaHornear->cocinarse();

			this->semaforoCadetesLibres->p();
			ssize_t escritos = this->colaPizzaHorneadas->escribir((void*) pizzaHornear, len);
			if(escritos != (ssize_t) len){
				Logger::Instance()->log(Logger::ERROR," Se escribio mal la Pizza  " + pizzaHornear->getGusto() );
			}
			Logger::Instance()->log(Logger::INFO,"Se cocino la Pizza de " + pizzaHornear->getGusto() );

			this->incrementarHornosLibres();
		}
		else{
			Logger::Instance()->log(Logger::ERROR," Se leyo  mal la Pizza  " );
		}
		delete pizzaHornear;
	}
}

void Horno::incrementarHornosLibres(){
	this->semaforoHornosLibres->v();
}
