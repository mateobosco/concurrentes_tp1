/*
 * Pizzeria.cpp
 *
 *  Created on: 25/4/2015
 *      Author: mateo
 */

#include "Pizzeria.h"

Pizzeria::Pizzeria() {

}

Pizzeria::~Pizzeria() {
}

void Pizzeria::crearGeneradorLlamados(){
	int pid_llamados = fork();
	if (pid_llamados == 0){//hijo generador de pedidos
//		std::cout << "Creo un generador de pedidos" << std::endl;
		GeneradorLlamados generador = GeneradorLlamados();
		generador.run();
	}
	else{
		this->childs.push_back(pid_llamados);
	}
}

void Pizzeria::crearRecepcionistas(int n){
	for (int i = 0; i < n ; i ++){
		int pid_recepcionista = fork();

		if (pid_recepcionista == 0){//Proceso hijo -> recepcionista
			Recepcionista r = Recepcionista();
//			std::cout << "Creo una recepcionista con pid "<< getpid() << std::endl;
			r.run();
			break;
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
			Cocinero c = Cocinero();
//			std::cout<<"Creo un cocinero con pid "<< getpid()<<std::endl;
			c.run();
			break;
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
			Horno h = Horno();
//			std::cout<<"Creo un horno con pid "<< getpid()<<std::endl;
			h.run();
			break;
		}
		else{
			this->childs.push_back(pid_horno);
		}
	}
}

void Pizzeria::run(){

	while (sigint_handler.getGracefulQuit() == 0){
	}

	for (size_t i = 0; i < this->childs.size() ; i++){
		int p = this->childs[i];
		kill(p,SIGINT);
	}
}
