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
	std::cout<<"Muere el Cocinero de pid" << getpid()<< std::endl;

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
		Zappi* pizzaCocinar = new Zappi("",0,0);
		size_t len = sizeof(Zappi);

		ssize_t leidos = this->colaPedidosCocinar->leer((void*) pizzaCocinar, len);

		if(leidos == (ssize_t) len){
			std::cout<< "COCINERO: leo una pizza"<<std::endl;
			this->ocuparHorno();
			ssize_t escritos = this->colaPizzasHornear->escribir((void*) pizzaCocinar, len);

			if (escritos != len){
				std::cout<< "COCINERO: ERROR Escribo " << escritos << std::endl;
			}
			else{
				//leer memoria compartida, si hay mas del doble de PT  que los PC
				// lockear a las recepcionistas. Despues deslockearlas.
			}
		}
		delete pizzaCocinar;
	}
}

void Cocinero::ocuparHorno(){
	this->semaforoPedidosPendientes->v();
	this->semaforoHornosLibres->p();
}
