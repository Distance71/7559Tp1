#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <iostream>
#include <string>
#include "../models/types.h"
#include "Logger.h"

class ErrorHandler {
    private:
        static ErrorHandler* instance;

    public:   
        static ErrorHandler* getInstance();
        void throwError(statusCode_t statusCode, std::string errorMsg);
};

#endif