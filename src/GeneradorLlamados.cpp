/*
 * GeneradorLlamados.cpp
 *
 *  Created on: 24/4/2015
 *      Author: mateo
 */

#include "GeneradorLlamados.h"


GeneradorLlamados::GeneradorLlamados() {
	this->seg = 1;
	this->fifoLlamadosGenerados = new FifoEscritura("/tmp/llamadosGenerados");
	this->fifoLlamadosGenerados->abrir();
	this->semaforoPizzeriaGracefulQuit = new Semaforo("aux/semaforoPizzeriaGracefulQuit.txt");
}

GeneradorLlamados::~GeneradorLlamados() {
	Logger::log(Logger::INFO, "Finaliza el proceso");
	this->semaforoPizzeriaGracefulQuit->eliminar();
	delete this->semaforoPizzeriaGracefulQuit;
	this->fifoLlamadosGenerados->cerrar();
	this->fifoLlamadosGenerados->eliminar();
	delete this->fifoLlamadosGenerados;
}

void GeneradorLlamados::run(){
	this->changeName("TP - GeneradorLlamados");

	this->semaforoIniciador->p();

	int i = 0;
	while (sigint_handler.getGracefulQuit() == 0){
		ZappiFactory zappiFactory;
		Zappi* pizza = zappiFactory.generarZappiRandom();
		size_t tamZappi = sizeof(Zappi);
		ssize_t escritos = this->fifoLlamadosGenerados->escribir(static_cast<const void*>(pizza), tamZappi);
		std::ostringstream os ;
		os << i;
		Logger::log(Logger::INFO,"El generador de llamados genera la Pizza nro: " + os.str() );
		if (escritos != (ssize_t)tamZappi){
			Logger::log(Logger::ERROR,"Problema al escribir la Pizza");
		}
		delete pizza;
		sleep(this->seg);
		i++;
	}
	Logger::log(Logger::INFO, "Se libera el semaforo para graceful quit");
	this->semaforoPizzeriaGracefulQuit->v();
}

