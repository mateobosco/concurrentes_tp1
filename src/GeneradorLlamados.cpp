/*
 * GeneradorLlamados.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "GeneradorLlamados.h"


GeneradorLlamados::GeneradorLlamados() {
	const std::string archivoPedidos = "/tmp/pedidos";
	this->seg = 1; //TODO no harcodear los parametros de los llamados(GeneradorLlamados)
	this->fifoLlamadosGenerados = new FifoEscritura(archivoPedidos);
	this->fifoLlamadosGenerados->abrir();
}

GeneradorLlamados::~GeneradorLlamados() {
	this->fifoLlamadosGenerados->cerrar();
	this->fifoLlamadosGenerados->eliminar();
	delete this->fifoLlamadosGenerados;
}

void GeneradorLlamados::run(){

	for (int i = 0 ; i < 10; i++){//TODO recibir senial para terminar elegantemente (GeneradorLlamados)
		Zappi* pizza = new Zappi("una de muzza", 10);
		size_t tamZappi = sizeof(Zappi);
		ssize_t escritos = this->fifoLlamadosGenerados->escribir((const void*) pizza, tamZappi);
		std::cout<<"Genere una pizza"<<std::endl;
		std::cout<< "Escribo " << escritos << std::endl;

		sleep(this->seg);
	}
}


