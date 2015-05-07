//
// Created by juan on 29/04/15.
//

#include "Supervisora.h"

Supervisora::Supervisora(int segundos) {
	this->segundos = segundos;
	this->memoriaCompartidaCaja = new MemoriaCompartida<Caja>();
	int estadoMemoria = this->memoriaCompartidaCaja->crear("aux/memoriaCompartidaCaja.txt",'R');
	if (estadoMemoria != SHM_OK){
		Logger::Instance()->log(Logger::ERROR,"Problema al crear la Memoria Compartida de la Caja");
	}
	this->lockMemoriaCompartidaCaja = new LockFile("aux/lockMemoriaCompartidaCaja.txt");
}

Supervisora::~Supervisora() {
	Logger::Instance()->log(Logger::INFO, "Finaliza el proceso");

	this->memoriaCompartidaCaja->liberar();
	delete this->memoriaCompartidaCaja;

	delete this->lockMemoriaCompartidaCaja;
}

void Supervisora::run(){
    this->changeName("TP - Supervisora");

    this->semaforoIniciador->p();

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
	std::ostringstream os ;
	os << total;
	Logger::Instance()->log(Logger::INFO,"La supervisora revisa la caja y hay " + os.str());
	this->lockMemoriaCompartidaCaja->liberarLock();
}
