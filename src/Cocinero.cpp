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
}

Cocinero::~Cocinero() {
	std::cout<<"Muere el Cocinero de pid" << getpid()<< std::endl;
	this->colaPedidosCocinar->cerrar();
	this->colaPedidosCocinar->eliminar();
	delete this->colaPedidosCocinar;
}

void Cocinero::run(){
	for( int i = 0; i< 10 ; i++){
		Zappi* pizzaCocinar = new Zappi("",0);
		size_t len = sizeof(Zappi);
		std::cout << "Espero para leer y soy Cocinero "<<getpid() << std::endl;
		ssize_t leidos = this->colaPedidosCocinar->leer((void*) pizzaCocinar, len);

		if(leidos == len){
			std::cout<< "Soy el cocinero y leo una pizza"<<std::endl;
//			pizzaCocinar->cocinar();
		}

	}
}

