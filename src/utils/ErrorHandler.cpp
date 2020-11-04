#include "ErrorHandler.h"

ErrorHandler* ErrorHandler::instance = nullptr;

void ErrorHandler::throwError(statusCode_t statusCode, std::string errorMsg){
    std::cerr << errorMsg << std::endl;
    Logger *logger;
    logger->getInstance()->log("Error: " + errorMsg);
}

ErrorHandler* ErrorHandler::getInstance() {
  if (instance == nullptr)
    instance = new ErrorHandler();
  return instance;
}