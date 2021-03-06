#include "Logger.h"

Logger* Logger::instance = nullptr;
bool Logger::debugMode = false;

Logger::Logger(const string& type_){
	mkdir(LOG_FOLDER, 0777);
	this->logFile = new ofstream();
	this->logFile->open(LOG_FOLDER + getTime() + "_" + type_+ "_log.txt");
	if (!this->logFile){
	    std::cerr << "ERROR creando archivo log. No se puede continuar. \n";
	    exit(1);
	 }

	 *(this->logFile) << "##################################################\n"
	 				  << "# TECNICAS DE PROGRAMACION CONCURRENTE I - CATEDRA GARIBALDI \n"
					  << "# 2° Cuatrimestre 2020 - " << getFullTime()
					  << "##################################################\n\n";
	this->logFile->flush();
}

Logger* Logger::getInstance()
{
  if (instance == nullptr)
    instance = new Logger("");
  return instance;
}

string Logger::getFullTime(){
	time_t timestamp;
	time(&timestamp);
	string timestamp_transform(ctime(&timestamp));
	return timestamp_transform;
}

string Logger::getTime(){
	return (getFullTime()).substr(4,15);
}

void Logger::log(const string& message) {
	if(debugMode) {
		*(this->logFile) << getTime() << " - " << message << " \n";
    	this->logFile->flush();
	}
}

void Logger::setDebug() {
	debugMode = true;
}

Logger::~Logger(){
	this->logFile->close();
	delete this->logFile;
}
