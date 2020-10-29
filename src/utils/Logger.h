#ifndef _LOGGER_H_
#define _LOGGER_H_

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

        Logger(const string& type_);
        string getTime();
        string getFullTime();

    public:   
        static Logger* getInstance();
        static void setTypeInstance(const string& type_);
        void log(const string& message);
        virtual ~Logger();
};

#endif