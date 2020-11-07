#ifndef FIFO_READ_H_
#define FIFO_READ_H_

#include "Fifo.h"

class FifoRead : public Fifo {
public:
	FifoRead(const std::string name);
	~FifoRead();

	void openFifo();
	ssize_t readFifo(void* buffer,const ssize_t buffsize) const;
};

#endif
