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

	this->semaforoPedidosPendientes = new Semaforo("semaforoPedidosPendientes.txt");
}

Recepcionista::~Recepcionista() {
	Logger::Instance()->log(Logger::INFO, "Finaliza el proceso");

	this->colaPedidosRecibir->cerrar();
	this->colaPedidosRecibir->eliminar();
	delete this->colaPedidosRecibir;

	this->colaPedidosCocinar->cerrar();
	this->colaPedidosCocinar->eliminar();
	delete this->colaPedidosCocinar;

	this->semaforoPedidosPendientes->eliminar();
	delete this->semaforoPedidosPendientes;
}

void Recepcionista::run(){
	this->changeName("TP - Recepcionista");

	this->semaforoIniciador->p();

	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaLeida = new Zappi();
		size_t len = sizeof(Zappi);

		ssize_t leidos = this->colaPedidosRecibir->leer((void*) pizzaLeida, len);
		this->semaforoPedidosPendientes->v();

		if (leidos == (ssize_t)len){
			Logger::Instance()->log(Logger::INFO,"La Recepcionista toma el pedido de una pizza de  " + pizzaLeida->getGusto() );

			ssize_t escritos = this->colaPedidosCocinar->escribir((void*) pizzaLeida, len);
			if (escritos != (ssize_t) len){
				Logger::Instance()->log(Logger::ERROR," Problema al escribir la Pizza de "+ pizzaLeida->getGusto() );
			}
		}
		else{
			Logger::Instance()->log(Logger::ERROR,"Problema al leer la Pizza " );
		}
		delete pizzaLeida;
	}
}

