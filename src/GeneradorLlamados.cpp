/*
 * GeneradorLlamados.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "GeneradorLlamados.h"


GeneradorLlamados::GeneradorLlamados() {
	this->seg = 1; //TODO no harcodear los parametros de los llamados(GeneradorLlamados)
	this->fifoLlamadosGenerados = new FifoEscritura("/tmp/llamadosGenerados");
	this->fifoLlamadosGenerados->abrir();

	this->semaforoPizzeriaGracefulQuit = new Semaforo("aux/semaforoPizzeriaGracefulQuit.txt");
}

GeneradorLlamados::~GeneradorLlamados() {
	std::cout << "Muere Generador de Llamados " << getpid() << std::endl;

	this->semaforoPizzeriaGracefulQuit->eliminar();
	delete this->semaforoPizzeriaGracefulQuit;

	this->fifoLlamadosGenerados->cerrar();
	this->fifoLlamadosGenerados->eliminar();
	delete this->fifoLlamadosGenerados;
}

void GeneradorLlamados::run(){
	this->changeName("TP - GeneradorLlamados");
	int i = 0;
	while (sigint_handler.getGracefulQuit() == 0){

		Zappi* pizza = new Zappi("una de muzza", 10, 50);
		size_t tamZappi = sizeof(Zappi);
		ssize_t escritos = this->fifoLlamadosGenerados->escribir(static_cast<const void*>(pizza), tamZappi);
		std::cout<<"GENERADORPIZZAS: Genere la pizza nro: " << i <<" de gusto: "<<pizza->getGusto()<<std::endl;

		if (escritos != (ssize_t)tamZappi){
			std::cout<< "GENERADORPIZZAS: ERROR Escribo " << escritos << std::endl;
		}

		delete pizza;
		sleep(this->seg);
		i++;
	}
	std::cout<< "LIBERO EL SEMAFORO PARA GRACEFUL QUIT"<< std::endl;
	this->semaforoPizzeriaGracefulQuit->v();
}


