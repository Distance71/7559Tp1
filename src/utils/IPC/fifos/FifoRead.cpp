#include "FifoRead.h"

FifoRead::FifoRead(const std::string name) : Fifo(name) {
}

FifoRead::~FifoRead() {
}

void FifoRead::openFifo() {
	fd = open(name.c_str(), O_RDONLY);
}

ssize_t FifoRead::readFifo(void* buffer, const ssize_t buffsize) const {
	return read(fd, buffer, buffsize);
}
