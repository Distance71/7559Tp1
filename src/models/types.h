#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <string>

typedef unsigned int pixel_t;

typedef enum statusCode {
    OK = 0,
    GENERIC_ERROR = 1,
} statusCode_t;

typedef struct status {
    statusCode_t code;
    std::string errorMsg;
} status_t;

typedef struct resolution {
	size_t height;
	size_t width;
} resolution_t;

#endif