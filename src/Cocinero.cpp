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
	//for( int i = 0; i< 10 ; i++){
	this->changeName("TP - Cocinero");
	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaCocinar = new Zappi("",0,0);
		size_t len = sizeof(Zappi);
		ssize_t leidos = this->colaPedidosCocinar->leer((void*) pizzaCocinar, len);
		if(leidos == (ssize_t) len){
			std::cout<< "COCINERO: leo una pizza"<<std::endl;
			Logger::log(Logger::INFO,"Un Cocinero toma el pedido de una pizza de " + pizzaCocinar->getGusto() );
			this->ocuparHorno();
			ssize_t escritos = this->colaPizzasHornear->escribir((void*) pizzaCocinar, len);
			if (escritos != len){
				std::cout<< "COCINERO: ERROR Escribo " << escritos << std::endl;
				Logger::log(Logger::ERROR," Problema al escribir la pizza de "+ pizzaCocinar->getGusto());
			}
		}
		else{
			Logger::log(Logger::ERROR," Problema al leer la pizza ");
		}
		delete pizzaCocinar;
	}
}

void Cocinero::ocuparHorno(){
	this->semaforoPedidosPendientes->v();
	this->semaforoHornosLibres->p();
}
