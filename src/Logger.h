/*
 * Logger.h
 *
 *  Created on: 29/4/2015
 *      Author: mateo
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <sys/prctl.h>


#include "structures/LockFile.h"

class Logger {
public:
	Logger();
	virtual ~Logger();

	static std::string file;
	static int ERROR;
	static int INFO;

	static void log(int level, std::string message);
	static std::string getTime();
	static std::string getProcessInfo();
};

#endif /* LOGGER_H_ */
