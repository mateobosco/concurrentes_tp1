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
		Logger::log(Logger::INFO,"ERROR: Error al crear la Memoria Compartida en el Cadete");
	}
	this->lockMemoriaCompartidaCaja = new LockFile("aux/lockMemoriaCompartidaCaja.txt");
}

Cadete::~Cadete() {
	this->colaPizzasHorneadas->cerrar();
	this->colaPizzasHorneadas->eliminar();
	delete this->colaPizzasHorneadas;

	this->memoriaCompartidaCaja->liberar();
	delete this->memoriaCompartidaCaja;

	delete this->lockMemoriaCompartidaCaja;
}

void Cadete::run(){
	this->changeName("TP - Cadete");

	this->semaforoIniciador->p();

	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHorneada = new Zappi("",0,0);
		size_t len = sizeof(Zappi);
//		std::cout << "CADETE: Espero para leer"<<getpid() << std::endl;
		ssize_t leidos = this->colaPizzasHorneadas->leer((void*) pizzaHorneada, len);
		if(leidos == (ssize_t) len){
			Logger::log(Logger::INFO,"El cadete agarra y entrega un pizza de " + pizzaHorneada->getGusto());
			std::cout<< "CADETE : leo una pizza"<<std::endl;
		}
		else{
			Logger::log(Logger::ERROR," Error al leer la pizza");
		}
		this->depositarEnCaja(pizzaHorneada->getPrecio());

		delete pizzaHorneada;
	}
}

void Cadete::depositarEnCaja(int precio) {
	this->lockMemoriaCompartidaCaja->tomarLock();
	Caja caja = this->memoriaCompartidaCaja->leer();
	caja.sumarAlTotal(precio);
	Logger::log(Logger::INFO,"El el cadete guardo en la caja " + std::to_string(precio));
	this->memoriaCompartidaCaja->escribir(caja);
	this->lockMemoriaCompartidaCaja->liberarLock();
}
