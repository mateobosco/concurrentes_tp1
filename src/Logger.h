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

//class Logger {
//public:
//	Logger();
//	virtual ~Logger();
//
//	static std::string file;

//
//	static void log(int level, std::string message);
//	static std::string getTime();
//	static std::string getProcessInfo();
//};

class Logger{
public:
	static int ERROR;
	static int INFO;
	static Logger* Instance();
	static std::string file;
	bool loggearBool;
	//bool openLogFile(std::string logFile);
	void log(int level, std::string message);
	static std::string getTime();
	static std::string getProcessInfo();

private:
	Logger(){};  // Private so that it can  not be called
	Logger(Logger const&){};             // copy constructor is private
	Logger& operator=(Logger const&){};  // assignment operator is private
	static Logger* m_pInstance;
};


#endif /* LOGGER_H_ */
