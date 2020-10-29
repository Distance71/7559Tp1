#ifndef OBSERVATORY_H
#define OBSERVATORY_H

#include "Camera.h"
#include "Photo.h"
#include "Image.h"

class Observatory {
	private:
    	std::vector<Camera*> cameras;
		Photo* lastPhoto;
	
    	std::vector<Image*> takeImages();
    	void adjustImages();
    	void combineImages();

	public:
    	Observatory(size_t quantityCameras, resolution_t resolution);

    	Photo* takePhoto();
};

#endif