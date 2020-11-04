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

template <class T> class SharedMemory {
	private:
		int shmId;
		T*	ptrData;

		int attachedProcesses();

	public:
		SharedMemory();
		~SharedMemory();
		int create(const std::string &fileName, const char letter);
		int free();

		void write(const T &data);
		T read() const;
};

template <class T> SharedMemory <T>::SharedMemory() : shmId (0), ptrData (NULL) {}

template <class T> SharedMemory <T>::~SharedMemory() {
	this->free();
}

template <class T> int SharedMemory <T>::create(const std::string &fileName, const char letter ) {
	ErrorHandler* errorHandler;
	key_t key = ftok(fileName.c_str(), letter);
	if(key == -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory Error en ftok(): " + std::string(strerror(errno)));
		return -1;
	}
	
	this->shmId = shmget(key, sizeof(T), 0644 | IPC_CREAT);
	if (this->shmId == -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory: Error en shmget(): " + std::string(strerror(errno)));
		return -1;
	}

	void* tmpPtr = shmat(this->shmId, NULL, 0);
	
	if (tmpPtr == (void *) -1) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "SharedMemory: Error en shmat(): " + std::string(strerror(errno)));
		return -1;
	}

	this->ptrData = static_cast<T*> (tmpPtr);
	return 0;
}

template <class T> int SharedMemory <T>::free() {
	ErrorHandler* errorHandler;
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
}

template <class T> int SharedMemory <T>::attachedProcesses() {
	shmid_ds state;
	shmctl(this->shmId, IPC_STAT, &state);
	return state.shm_nattch;
}

template < class T > void SharedMemory <T>:: write(const T &data) {
	*(this->ptrData) = data;
}
template < class T > T SharedMemory <T>:: read() const {
	return *(this->ptrData);
}


#endif