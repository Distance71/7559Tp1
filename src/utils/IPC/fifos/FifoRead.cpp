#include "FifoRead.h"

FifoRead::FifoRead(const std::string name) : Fifo(name) {
}

FifoRead::~FifoRead() {
}

void FifoRead::openFifo() {
	Logger* logger;
	fd = open(name.c_str(), O_RDONLY);

	logger->getInstance()->log("El fifo se ha abierto");
}

ssize_t FifoRead::readFifo(void* buffer, const ssize_t buffsize) const {
	Logger* logger;
	logger->getInstance()->log("El fifo se va a leer");
	return read(fd, buffer, buffsize);
}
