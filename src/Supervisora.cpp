//
// Created by juan on 29/04/15.
//

#include "Supervisora.h"

Supervisora::Supervisora(int segundos) {
	this->segundos = segundos;
	this->memoriaCompartidaCaja = new MemoriaCompartida<Caja>();
	int estadoMemoria = this->memoriaCompartidaCaja->crear("aux/memoriaCompartidaCaja.txt",'R');
	if (estadoMemoria != SHM_OK){
		Logger::log(Logger::ERROR,"Problema al crear la Memoria Compartida de la Caja");
	}
	this->lockMemoriaCompartidaCaja = new LockFile("aux/lockMemoriaCompartidaCaja.txt");
}

Supervisora::~Supervisora() {
	this->memoriaCompartidaCaja->liberar();
	delete this->memoriaCompartidaCaja;

	delete this->lockMemoriaCompartidaCaja;
}

void Supervisora::run(){
    this->changeName("TP - Supervisora");
    while (sigint_handler.getGracefulQuit() == 0){
    	this->controlarCaja();
    	this->dormir();
    }
}

void Supervisora::dormir(){
	sleep(this->segundos);
}

void Supervisora::controlarCaja(){
	this->lockMemoriaCompartidaCaja->tomarLock();
	Caja caja = this->memoriaCompartidaCaja->leer();
	int total = caja.getTotal();
	std::cout<<"SUPERVISORA: Leo que en la caja hay "<<total<<" pesos"<<std::endl;
	Logger::log(Logger::INFO,"La supervisora revisa la caja y checkea que hay " + std::to_string(total));
	this->lockMemoriaCompartidaCaja->liberarLock();
}
