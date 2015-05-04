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
	int pid = getpid();
	cout << "!!!PROCESO!!! "<< pid << endl;

	Pizzeria p = Pizzeria();
	if (getpid() == pid) p.crearCaja();
	if (getpid() == pid) p.crearGeneradorLlamados();
	if (getpid() == pid) p.crearRecepcionistas(1);
	if (getpid() == pid) p.crearCocineros(1);
	if (getpid() == pid) p.crearHornos(1);
	if (getpid() == pid) p.crearCadetes(1);
	if (getpid() == pid) p.crearSupervisora(4);
	if (getpid() == pid) p.run();

	cout<<"FINALIZA EL PROGRAMA"<<endl;
	return 0;
}
