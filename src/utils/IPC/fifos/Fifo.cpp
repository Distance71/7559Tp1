#include "Fifo.h"

Fifo::Fifo(const std::string name) : name(name), fd(-1) {
	mknod ( static_cast<const char*>(name.c_str()),S_IFIFO|0666,0 );
}

Fifo::~Fifo() {
}

void Fifo::closeFifo() {
	Logger* logger;
	close(fd);
	fd = -1;
	logger->getInstance()->log("El fifo se ha cerrado");
}

void Fifo::free() const {
	Logger* logger;
	unlink ( name.c_str() );
	logger->getInstance()->log("El fifo se ha liberado");
}
