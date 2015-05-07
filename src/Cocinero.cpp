/*
 * Cocinero.cpp
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#include "Cocinero.h"

Cocinero::Cocinero() {
	this->colaPedidosCocinar = new FifoLectura("/tmp/pedidosCocinar");
	this->colaPedidosCocinar->abrir();

	this->colaPizzasHornear = new FifoEscritura("/tmp/pizzasHornear");
	this->colaPizzasHornear->abrir();

	this->semaforoHornosLibres = new Semaforo("aux/semaforoHornosLibres.txt");
	this->semaforoPedidosPendientes = new Semaforo("semaforoPedidosPendientes.txt");
}

Cocinero::~Cocinero() {
	Logger::log(Logger::INFO, "Finaliza el proceso");
	this->colaPedidosCocinar->cerrar();
	this->colaPedidosCocinar->eliminar();
	delete this->colaPedidosCocinar;

	this->colaPizzasHornear->cerrar();
	this->colaPizzasHornear->eliminar();
	delete this->colaPizzasHornear;

	this->semaforoHornosLibres->eliminar();
	delete this->semaforoHornosLibres;

	this->semaforoPedidosPendientes->eliminar();
	delete this->semaforoPedidosPendientes;
}

void Cocinero::run(){
	this->changeName("TP - Cocinero");

	this->semaforoIniciador->p();

	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaCocinar = new Zappi();
		size_t len = sizeof(Zappi);
		ssize_t leidos = this->colaPedidosCocinar->leer((void*) pizzaCocinar, len);
		if(leidos == (ssize_t) len){
			Logger::log(Logger::INFO,"Un Cocinero toma el pedido de una pizza de " + pizzaCocinar->getGusto() );
			this->ocuparHorno();
			ssize_t escritos = this->colaPizzasHornear->escribir((void*) pizzaCocinar, len);
			if (escritos != (ssize_t) len){
				Logger::log(Logger::ERROR,"Escribir pizza en colaPizzasHornear");
			}
		}
		else{
			Logger::log(Logger::ERROR,"Leer pizza de colaPedidosCocinar");
		}
		delete pizzaCocinar;
	}
}

void Cocinero::ocuparHorno(){
	this->semaforoPedidosPendientes->v();
	this->semaforoHornosLibres->p();
}
