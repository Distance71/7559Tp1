#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include <string.h>
#include <iostream>
#include <errno.h>
#include "ErrorHandler.h"
#include "Logger.h"

template <class T> class SharedMemory {
	private:
		int shmId;
		T	ptrData;
		int attachedProcesses();

	public:
		SharedMemory();
		~SharedMemory();
		int create(const std::string &fileName, const char letter, size_t nBytes);
		int free();

		void write(const T &data, size_t nBytes, size_t elementBytes );
		T read();
};

template <class T> SharedMemory <T>::SharedMemory() : shmId (0), ptrData (NULL) {}

template <class T> SharedMemory <T>::~SharedMemory() {
	this->free();
}

template <class T> int SharedMemory <T>::create(const std::string &fileName, const char letter, size_t nBytes ) {
	Logger* logger;
	ErrorHandler* errorHandler;
	key_t key = ftok(fileName.c_str(), letter);
	if(key == -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory Error en ftok(): " + std::string(strerror(errno)));
		return -1;
	}
	
	this->shmId = shmget(key, nBytes, 0644 | IPC_CREAT);
	if (this->shmId == -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory: Error en shmget(): " + std::string(strerror(errno)));
		return -1;
	}

	void* tmpPtr = shmat(this->shmId, NULL, 0);
	
	if (tmpPtr == (void *) -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory: Error en shmat(): " + std::string(strerror(errno)));
		return -1;
	}

	this->ptrData = static_cast<T> (tmpPtr);
	logger->getInstance()->log("La memoria se ha podido crear con exito");
	return 0;
}

template <class T> int SharedMemory <T>::free() {
	ErrorHandler* errorHandler;
	Logger* logger;
	int errorDt = shmdt((void *) this->ptrData);
	
	if(errorDt == -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory: Error en shmdt(): " + std::string(strerror(errno)));
		return -1;
	}

	int attachedProcesses = this->attachedProcesses();

	if(attachedProcesses == 0) {
		int resultCode = shmctl(this->shmId, IPC_RMID, NULL);

		if(resultCode == -1) {
			errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory: Error en shmctl(): " + std::string(strerror(errno)));
			return -1;
		}
	}
	logger->getInstance()->log("La memoria se ha podido liberar con exito");
}

template <class T> int SharedMemory <T>::attachedProcesses() {
	shmid_ds state;
	shmctl(this->shmId, IPC_STAT, &state);
	return state.shm_nattch;
}

template < class T > void SharedMemory <T>:: write(const T &data, size_t nBytes, size_t elementBytes ) {
	Logger* logger;

	size_t bytesUsed = 0;

	const size_t quantityElements = nBytes / elementBytes;

	for(size_t j = 0; j < quantityElements; j++) {
		*(this->ptrData + bytesUsed) = *(data + bytesUsed);
		bytesUsed += elementBytes;
	}

	logger->getInstance()->log("La memoria se ha podido escribir con exito");
}
template < class T > T SharedMemory <T>:: read() {
	Logger* logger;
	logger->getInstance()->log("La memoria se va a leer");
	return this->ptrData;
}

#endif