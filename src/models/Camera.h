#ifndef CAMERA_H
#define CAMERA_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "types.h"
#include "Image.h"

class Camera {
	private:
    	resolution_t resolution;

    	std::vector<pixel_t> generateImagePixels();

	public:
    	Camera(resolution_t resolution);

    	Image* shot();
};

#endif