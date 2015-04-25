/*
 * Recepcionista.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "Recepcionista.h"

Recepcionista::Recepcionista() {
	this->colaPedidosRecibir = new FifoLectura("/tmp/pedidos");
	this->colaPedidosRecibir->abrir();

	this->colaPedidosCocinar = new FifoEscritura("/tmp/pedidosCocinar");
	this->colaPedidosCocinar->abrir();
}

Recepcionista::~Recepcionista() {
	std::cout << "Muere Recepcionista " << getpid() << std::endl;
	this->colaPedidosRecibir->cerrar();
	this->colaPedidosRecibir->eliminar();
	delete this->colaPedidosRecibir;

	this->colaPedidosCocinar->cerrar();
	this->colaPedidosCocinar->eliminar();
	delete this->colaPedidosCocinar;
}

void Recepcionista::run(){
	for (int i = 0 ; i < 10; i++){ //TODO: salida elegante para Recepcionista

		Zappi* pizzaLeida = new Zappi("",0);
		size_t len = sizeof(Zappi);
		std::cout << "Espero para leer y soy Recepcionista "<<getpid() << std::endl;
		ssize_t leidos = this->colaPedidosRecibir->leer((void*) pizzaLeida, len);

		if (leidos == len){
			std::cout << "Lei una pizza y soy Recepcionista " << getpid() << std::endl;
			this->colaPedidosCocinar->escribir((void*) pizzaLeida, len);

		}
//		delete pizzaLeida;




	}
}

