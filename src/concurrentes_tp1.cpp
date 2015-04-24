//============================================================================
// Name        : concurrentes_tp1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>

#include "GeneradorLlamados.h"
#include "Recepcionista.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int pid_llamados = fork();
	if (pid_llamados == 0){//hijo generador de pedidos
		cout << "Creo un generador de pedidos" << endl;
		GeneradorLlamados generador = GeneradorLlamados();
		generador.run();
	}
	else{
		for (int i = 0; i < 2 ; i ++){
				int pid_recepcionista = fork();

				if (pid_recepcionista == 0){//hijo recepcionista
					Recepcionista r = Recepcionista();
					cout << "Creo una recepcionista con pid"<< getpid() << endl;
					r.run();
					break;
				}
			}
		}

	return 0;
}
