/*
 * Recepcionista.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "Recepcionista.h"

Recepcionista::Recepcionista() {
	this->colaPedidosRecibir = new FifoLectura("/tmp/llamadosGenerados");
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
	this->changeName("TP - Recepcionista");
	while (sigint_handler.getGracefulQuit() == 0){

		Zappi* pizzaLeida = new Zappi("",0);
		size_t len = sizeof(Zappi);
		std::cout << "RECEPCIONISTA Espero para leer "<<getpid() << std::endl;
		ssize_t leidos = this->colaPedidosRecibir->leer((void*) pizzaLeida, len);

		if (leidos == len){
			std::cout << "RECEPCIONISTA Lei una pizza de: "<<pizzaLeida->getGusto() << getpid() << std::endl;
			ssize_t escritos = this->colaPedidosCocinar->escribir((void*) pizzaLeida, len);
			if (escritos != len){
				std::cout<< "RECEPCIONISTA: ERROR Escribo " << escritos << std::endl;
			}
			else{
				//leer en mem compartida cant de pedidos tomados
				//sumar 1, escribir en mem compartida.

			}
		}
		delete pizzaLeida;
	}
}

