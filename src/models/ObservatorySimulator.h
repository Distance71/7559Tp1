#ifndef OBSERVATORY_SIMULATOR_H
#define OBSERVATORY_SIMULATOR_H

#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include "Observatory.h"
#include "types.h"
#include "../utils/Logger.h"
#include "../utils/IPC/SharedMemory.h"
#include "../utils/ErrorHandler.h"
#include "../utils/IPC/signals/SIGINT_Handler.h"
#include "../utils/IPC/signals/SignalHandler.h"
#include "../utils/IPC/fifos/FifoRead.h"
#include "../utils/IPC/fifos/FifoWrite.h"

#define INIT_SIZE 1000
#define FILE_FIFO "/tmp/archivo_fifo"

class ObservatorySimulator {
	private:
        Observatory* observatory;
		size_t* lastPhotoImagesSerialized;
		size_t lastPhotoImagesSerializedSize;
		size_t quantityCameras;

		int takePhoto();
		int processImagesSharedMem();
		int processImagesFifos();
	public:
    	ObservatorySimulator(size_t quantityCameras, resolution_t camerasResolution);

        void runSharedMem();
		void runFifos();
};

#endif