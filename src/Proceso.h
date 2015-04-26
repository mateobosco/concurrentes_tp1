/*
 * Proceso.h
 *
 *  Created on: 26/4/2015
 *      Author: mateo
 */

#ifndef PROCESO_H_
#define PROCESO_H_

#include "structures/SIGINT_Handler.h"
#include "structures/SignalHandler.h"

class Proceso {
public:
	Proceso();
	virtual ~Proceso();
	SIGINT_Handler sigint_handler;
};

#endif /* PROCESO_H_ */
