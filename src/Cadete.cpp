/*
 * Cadete.cpp
 *
 *  Created on: 28/4/2015
 *      Author: mateo
 */

#include "Cadete.h"
#include "Caja.h"
#include "structures/LockFile.h"

using namespace std;

Cadete::Cadete() {
	this->colaPizzasHorneadas = new FifoLectura("/tmp/pizzasHorneadas");
	this->colaPizzasHorneadas->abrir();
}

Cadete::~Cadete() {
	this->colaPizzasHorneadas->cerrar();
	this->colaPizzasHorneadas->eliminar();
	delete this->colaPizzasHorneadas;
}

void Cadete::run(){
	this->changeName("TP - Cadete");
	while (sigint_handler.getGracefulQuit() == 0){
		Zappi* pizzaHorneada = new Zappi("",0,0);
		size_t len = sizeof(Zappi);
		std::cout << "CADETE: Espero para leer"<<getpid() << std::endl;
		ssize_t leidos = this->colaPizzasHorneadas->leer((void*) pizzaHorneada, len);

		if(leidos == len){
			std::cout<< "CADETE : leo una pizza"<<std::endl;
		}
		cout << " ================= CADETE LEE EL PRECIO DE LA ZAPPI  " << pizzaHorneada->getPrecio() << " pesos " << endl;
		this->depositarEnCaja(pizzaHorneada->getPrecio());

		delete pizzaHorneada;
	}


}

void Cadete::depositarEnCaja(int total) {
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	string archivo = string(cwd);
	archivo.append("/src/Pizzeria.cpp"); // TODO VER COMO ARREGLAR ESTO
	LockFile lock ( "Cadete.cpp" );
	lock.tomarLock();
	cout << "Cadete" << getpid() << "toma el lock" << endl;
	MemoriaCompartida<Caja> memoria;
	Caja caja;
	int estadoMemoria = memoria.crear(archivo, 'R');
	if (estadoMemoria == SHM_OK) {
		caja = memoria.leer();
		cout << "Cadete ve que en la caja hay " << caja.getTotal() << " pesos " << endl;
		cout << "Cadete deposita lo cobrado en la caja " << endl;
		caja.sumaralTotal(total);
		cout << "Ahora en la caja hay " << caja.getTotal() << " pesos " << endl;

		memoria.escribir(caja);
		//memoria.escribir ( resultado+total );

		// memoria.liberar (); TODO ver cuando liberar
	} else {
		cout << "Hijo: error en memoria compartida: " << estadoMemoria << endl;
	}
	lock.liberarLock();
	cout << "El cadete "<< getpid() << "libero el lock" << endl;

}
