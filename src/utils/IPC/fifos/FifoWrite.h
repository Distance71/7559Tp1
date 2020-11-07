#ifndef FIFO_WRITE_H_
#define FIFO_WRITE_H_

#include "Fifo.h"

class FifoWrite : public Fifo {
public:
	FifoWrite(const std::string name);
	~FifoWrite();

	void openFifo();
	ssize_t writeFifo(const void* buffer, const ssize_t buffsize) const;
};

#endif