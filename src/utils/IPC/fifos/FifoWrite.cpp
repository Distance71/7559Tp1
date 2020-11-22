#include "FifoWrite.h"

FifoWrite::FifoWrite(const std::string name) : Fifo(name) {
}

FifoWrite::~FifoWrite() {
}

void FifoWrite::openFifo() {
	Logger* logger;
	fd = open(name.c_str(), O_WRONLY);
	logger->getInstance()->log("El fifo se ha abierto");
}

ssize_t FifoWrite::writeFifo(const void* buffer, const ssize_t buffsize) const {
	Logger* logger;
	logger->getInstance()->log("El fifo se va a escribir");
	return write(fd, buffer, buffsize);
}
