/*
 * Cadete.cpp
 *
 *  Created on: 28/4/2015
 *      Author: mateo
 */

#include "Cadete.h"

using namespace std;

Cadete::Cadete() {
	this->colaPizzasHorneadas = new FifoLectura("/tmp/pizzasHorneadas");
	this->colaPizzasHorneadas->abrir();

	this->memoriaCompartidaCaja = new MemoriaCompartida<Caja>();

	int estadoMemoria = this->memoriaCompartidaCaja->crear("aux/memoriaCompartidaCaja.txt",'R');
	if (estadoMemoria != SHM_OK){
		Logger::Instance()->log(Logger::INFO,"ERROR: Error al crear la Memoria Compartida en el Cadete");
	}
	this->lockMemoriaCompartidaCaja = new LockFile("aux/lockMemoriaCompartidaCaja.txt");

	this->semaforoCadetesLibres = new Semaforo("aux/semaforoCadetesLibres.txt");
	this->liberarCadete();
}

Cadete::~Cadete() {
	Logger::Instance()->log(Logger::INFO, "Finaliza el proceso");
	this->colaPizzasHorneadas->cerrar();
	this->colaPizzasHorneadas->eliminar();
	delete this->colaPizzasHorneadas;

	this->memoriaCompartidaCaja->liberar();
	delete this->memoriaCompartidaCaja;

	delete this->lockMemoriaCompartidaCaja;

	this->semaforoCadetesLibres->eliminar();
	delete this->semaforoCadetesLibres;
}

void Cadete::run(){
	this->changeName("TP - Cadete");

	this->semaforoIniciador->p();

	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHorneada = new Zappi();
		size_t len = sizeof(Zappi);
		ssize_t leidos = this->colaPizzasHorneadas->leer((void*) pizzaHorneada, len);
		if(leidos == (ssize_t) len){
			Logger::Instance()->log(Logger::INFO,"El cadete agarra y entrega un pizza de " + pizzaHorneada->getGusto());
		}
		else{
			Logger::Instance()->log(Logger::ERROR," Error al leer la pizza");
		}
		this->depositarEnCaja(pizzaHorneada->getPrecio());
		this->liberarCadete();

		delete pizzaHorneada;
	}
}

void Cadete::depositarEnCaja(int precio) {
	this->lockMemoriaCompartidaCaja->tomarLock();
	Caja caja = this->memoriaCompartidaCaja->leer();
	caja.sumarAlTotal(precio);
	Logger::Instance()->log(Logger::INFO,"El el cadete guardo en la caja " + std::to_string(precio));
	this->memoriaCompartidaCaja->escribir(caja);
	this->lockMemoriaCompartidaCaja->liberarLock();
}

void Cadete::liberarCadete(){
	this->semaforoCadetesLibres->v();
}
