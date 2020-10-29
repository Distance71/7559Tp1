#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include <string.h>
#include <iostream>
#include <errno.h>

template <class T> class SharedMemory {
	private:
		int shmId;
		T*	ptrData;

		int attachedProcesses();

	public:
		SharedMemory();
		~SharedMemory();
		void create(const std::string &fileName, const char letter);
		void free();

		void write(const T &data);
		T read() const;
};

template <class T> SharedMemory <T>::SharedMemory() : shmId (0), ptrData (NULL) {}

template <class T> SharedMemory <T>::~SharedMemory() {
	this->free();
}

template <class T> void SharedMemory <T>::create (const std::string &fileName, const char letter ) {
	key_t key = ftok(fileName.c_str(), letter);
	if(key == -1) {
		std::string mensaje = std::string ( " Error en ftok () : " ) + std::string (strerror ( errno ));
		throw mensaje;
	}
	
	this->shmId = shmget(key, sizeof(T), 0644 | IPC_CREAT);
	if (this->shmId == -1) {
		std::string mensaje = std::string(" Error en shmget () : ") + std::string(strerror(errno));
		throw mensaje;
	}

	void* tmpPtr = shmat(this->shmId, NULL, 0);
	
	if ( tmpPtr == ( void *) -1 ) {
		std::string mensaje = std::string ( " Error en shmat () : " ) + std::string (strerror ( errno ));
		throw mensaje;
	}

	this->ptrDatos = static_cast<T*> (tmpPtr);
}

template <class T> void SharedMemory <T>::free() {
	int errorDt = shmdt (( void *) this->ptrDatos);
	
	if(errorDt == -1) {
		std :: string mensaje = std :: string ( " Error en shmdt () : " ) + std :: string ( strerror (
		errno ) ) ;
		throw mensaje ;
	}

	int attachedProcesses = this->attachedProcesses();

	if(procAdosados == 0) {
		shmctl(this->shmId, IPC_RMID, NULL);
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