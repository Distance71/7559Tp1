#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>
#include "types.h"

class Image {
	private:
    	std::vector<pixel_t> pixels;
		resolution_t resolution;
	
	public:
    	Image(std::vector<pixel_t> pixels, resolution_t resolution);

    	std::vector<pixel_t> getPixels();
    	void adjust();
		void print();
};

#endif