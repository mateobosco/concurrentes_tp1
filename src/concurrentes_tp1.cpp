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
	cout << "!!!Hello World!!!" << endl;

	Pizzeria p = Pizzeria();
	p.crearGeneradorLlamados();
	p.crearRecepcionistas(2);

	return 0;
}
