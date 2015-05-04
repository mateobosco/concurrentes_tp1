//============================================================================
// Name        : concurrentes_tp1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>


#include "Pizzeria.h"

using namespace std;

int main() {
	cout << "!!!PROCESO!!! "<< getpid() << endl;

	Pizzeria p = Pizzeria();
//	p.crearCaja();
	p.crearGeneradorLlamados();
	p.crearRecepcionistas(1);
	p.crearCocineros(1);
	p.crearHornos(1);
	p.crearCadetes(1);
//	p.crearSupervisora();
	p.run();

	return 0;
}
