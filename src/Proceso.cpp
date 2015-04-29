/*
 * Proceso.cpp
 *
 *  Created on: 26/4/2015
 *      Author: mateo
 */

#include "Proceso.h"

Proceso::Proceso() {
	SignalHandler :: getInstance()->registrarHandler ( SIGINT,&sigint_handler );
}

Proceso::~Proceso() {
	SignalHandler :: destruir ();
}

void Proceso::changeName(std::string name){

	const char* new_name = name.c_str();
	prctl(PR_SET_NAME, (unsigned long) new_name, 0, 0, 0);
}
