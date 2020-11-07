#include "FifoWrite.h"

FifoWrite::FifoWrite(const std::string name) : Fifo(name) {
}

FifoWrite::~FifoWrite() {
}

void FifoWrite::openFifo() {
	fd = open(name.c_str(), O_WRONLY);
}

ssize_t FifoWrite::writeFifo(const void* buffer, const ssize_t buffsize) const {
	return write(fd, buffer, buffsize);
}
