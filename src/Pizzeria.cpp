/*
 * Pizzeria.cpp
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#include "Pizzeria.h"

Pizzeria::Pizzeria() {
	this->changeName("TP - Pizzeria");
	this->lockPizzeria = new LockFile("lockPizzeria.txt");
	this->cantHornosLibres = new MemoriaCompartida<int>();
	this->cantHornosLibres->crear("cantHornosLibres.txt",'R');
	this->cantHornosLibres->escribir(0);

	this->lockHornosOcupados = new LockFile("lockHornosOcupados.txt");
	this->lockHornosOcupados->tomarLock();
}

Pizzeria::~Pizzeria() {
	delete this->lockPizzeria;
	this->cantHornosLibres->liberar();
	delete this->cantHornosLibres;
}

void Pizzeria::crearGeneradorLlamados(){
	int pid_llamados = fork();
	if (pid_llamados == 0){//hijo generador de pedidos
		std::cout << "Creo un generador de pedidos" << std::endl;
		Logger::log(Logger::INFO,"Creo el generador de llamados");
		GeneradorLlamados* generador = new GeneradorLlamados();
		generador->run();
		delete generador;
		exit(0);
	}
}

void Pizzeria::crearRecepcionistas(int n){
	for (int i = 0; i < n ; i ++){
		int pid_recepcionista = fork();

		if (pid_recepcionista == 0){//Proceso hijo -> recepcionista
			Recepcionista* r = new Recepcionista();
			std::cout << "Creo una recepcionista con pid "<< getpid() << std::endl;
			r->run();
			delete r;
			exit(0);
		}
		else{
			this->childs.push_back(pid_recepcionista);
		}
	}
}

void Pizzeria::crearCocineros(int n){
	for (int i = 0; i < n ; i++){
		int pid_cocinero = fork();
		if (pid_cocinero == 0) { //Proceso hijo -> cocinero
			Cocinero* c = new Cocinero();
			std::cout<<"Creo un cocinero con pid "<< getpid()<<std::endl;
			c->run();
			delete c;
			exit(0);
		}
		else{
			this->childs.push_back(pid_cocinero);
		}
	}
}

void Pizzeria::crearHornos(int n){
	for (int i = 0; i < n ; i++){
		int pid_horno = fork();
		if (pid_horno == 0) { //Proceso hijo -> horno
			Horno* h = new Horno();
			std::cout<<"Creo un horno con pid "<< getpid()<<std::endl;
			h->run();
			delete h;
			exit(0);
		}
		else{
			this->childs.push_back(pid_horno);
		}
	}
}

void Pizzeria::crearCadetes(int n){
	for (int i = 0 ; i < n ; i++){
		int pid_cadete = fork();
		if (pid_cadete == 0){ //Proceso hijo -> cadete
			Cadete* c = new Cadete();
			std::cout<<"Creo un cadete con pid "<< getpid()<<std::endl;
			c->run();
			delete c;
			exit(0);
		}
		else{
			this->childs.push_back(pid_cadete);
		}
	}
}

void Pizzeria::run(){

//	this->lockPizzeria->tomarLock();
	while(true){}
	Logger::log(Logger::INFO, "Se libera el lock para que terminen todos los procesos");

	for (size_t i = 0; i < this->childs.size() ; i++){
		int p = this->childs[i];
		std::cout<<"mato al hijo "<< p << std::endl;
		kill(p,SIGINT);
	}
	this->lockPizzeria->liberarLock();
}
