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

#define INIT_SIZE 1000

class ObservatorySimulator {
	private:
        Observatory* observatory;
		size_t* lastPhotoImagesSerialized;
		size_t quantityCameras;

		int takePhoto();
		int processImages();
	public:
    	ObservatorySimulator(size_t quantityCameras, resolution_t camerasResolution);

        void run();
};

#endif