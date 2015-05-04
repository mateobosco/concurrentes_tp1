/*
 * Configuracion.h
 *
 *  Created on: 4/5/2015
 *      Author: mateo
 */

#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <iostream>
#include <fstream>
#include <string>

class Configuracion {
public:
	Configuracion(std::string archivo);
	virtual ~Configuracion();

	int getCantRecepcionistas();
	int getCantCocineros();
	int getCantHornos();
	int getCantCadetes();
	int getTiempoSupervisora();

private:
	int recepcionistas;
	int cocineros;
	int hornos;
	int cadetes;
	int tiempo_supervisora;
};

#endif /* CONFIGURACION_H_ */

