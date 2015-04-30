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
}

Cocinero::~Cocinero() {
	std::cout<<"Muere el Cocinero de pid" << getpid()<< std::endl;

	this->colaPedidosCocinar->cerrar();
	this->colaPedidosCocinar->eliminar();
	delete this->colaPedidosCocinar;

	this->colaPizzasHornear->cerrar();
	this->colaPizzasHornear->eliminar();
	delete this->colaPizzasHornear;
}

void Cocinero::run(){
	//for( int i = 0; i< 10 ; i++){
	this->changeName("TP - Cocinero");
	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaCocinar = new Zappi("",0,0);
		size_t len = sizeof(Zappi);
		std::cout << "COCINERO Espero para leer "<<getpid() << std::endl;
		ssize_t leidos = this->colaPedidosCocinar->leer((void*) pizzaCocinar, len);

		if(leidos == len){
			std::cout<< "COCINERO: leo una pizza"<<std::endl;
//			pizzaCocinar->cocinar();
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

