#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <ctime>
#include <sys/stat.h>
#include <map>
#include <string>

#define LOG_FOLDER "../logs/"
using namespace std;

class Logger {
    private:
        static Logger* instance;
        ofstream* logFile;
        static bool debugMode;

        Logger(const string& type_);
        string getTime();
        string getFullTime();

    public:   
        static Logger* getInstance();
        void log(const string& message);
        virtual ~Logger();
        void setDebug();
};

#endif