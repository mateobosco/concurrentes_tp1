//============================================================================
// Name        : concurrentes_tp1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <unistd.h>


#include "Pizzeria.h"
#include "Logger.h"

using namespace std;

int main() {
	cout << "!!!PROCESO!!! "<< getpid() << endl;

	Logger::log(Logger::INFO, "Empieza el programa");

	Pizzeria p = Pizzeria();
	p.crearGeneradorLlamados();
	p.crearRecepcionistas(2);
	p.crearCocineros(2);
	p.crearHornos(2);
	p.crearCadetes(2);

	p.run();


	return 0;
}
