#ifndef OBSERVATORY_SIMULATOR_H
#define OBSERVATORY_SIMULATOR_H

#include "Observatory.h"
#include "types.h"
#include "../utils/Logger.h"

class ObservatorySimulator {
	private:
        Observatory* observatory;

		void takePhoto();
	public:
    	ObservatorySimulator(size_t quantityCameras, resolution_t camerasResolution);

        void run();
};

#endif