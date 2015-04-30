/*
 * Logger.cpp
 *
 *  Created on: 29/4/2015
 *      Author: mateo
 */

#include "Logger.h"

std::string Logger::file = "log.txt";
int Logger::ERROR = 2;
int Logger::INFO = 1;


Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::log(int level, std::string message){

	std::string line;
	if (level == Logger::INFO){
		line = Logger::getTime() + " - " + "INFO: " + message + " " + Logger::getProcessInfo() + "\n";
	}
	if (level == Logger::ERROR){
		line = Logger::getTime() + " - " + "ERROR: " + message + " " + Logger::getProcessInfo() + "\n";
	}

	char m[line.size()];
	memcpy(m,line.c_str(),line.size());

	LockFile lock(Logger::file.c_str());
	lock.tomarLock();
	int res = lock.escribir(static_cast<void*>(m), line.size());
	lock.liberarLock();
	if (res != line.size()){
		perror("Error al querer usar el logger");
	}
}

std::string Logger::getTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y/%m/%d %X", &tstruct);

	return buf;
}

std::string Logger::getProcessInfo(){
	char name[50];
	prctl(PR_GET_NAME, (unsigned long) name, 0, 0, 0);

	std::stringstream ss;
	ss << getpid();
	std::string pid;
	ss >> pid;

	std::string info = "PID: " + pid + " - " + std::string(name);
	return info;
}
