#ifndef OBSERVATORY_H
#define OBSERVATORY_H

#include <unistd.h>
#include <wait.h>
#include "Camera.h"
#include "Image.h"

class Observatory {
	private:
    	std::vector<Camera*> cameras;

	public:
    	Observatory(size_t quantityCameras, resolution_t resolution);

		std::vector<Image*> takeImages();
    	size_t* adjustImages(size_t* &images);
		void combineImages(size_t *images);
};

#endif