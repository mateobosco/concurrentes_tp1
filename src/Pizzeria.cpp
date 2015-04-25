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
		std::cout << "Creo un generador de pedidos" << std::endl;
		GeneradorLlamados generador = GeneradorLlamados();
		generador.run();
	}
}

void Pizzeria::crearRecepcionistas(int n){
	for (int i = 0; i < n ; i ++){
		int pid_recepcionista = fork();

		if (pid_recepcionista == 0){//Proceso hijo -> recepcionista
			Recepcionista r = Recepcionista();
			std::cout << "Creo una recepcionista con pid "<< getpid() << std::endl;
			r.run();
			break;
		}
	}
}

void Pizzeria::crearCocineros(int n){
	for (int i = 0; i < n ; i++){
		int pid_cocinero = fork();
		if (pid_cocinero == 0) { //Proceso hijo -> cocinero
			Cocinero c = Cocinero();
			std::cout<<"Creo un cocinero con pid "<< getpid()<<std::endl;
			c.run();
			break;
		}

	}

}
