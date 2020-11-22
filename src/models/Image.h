#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>
#include <string.h>
#include "types.h"
#include "../utils/ErrorHandler.h"
#include "../utils/Logger.h"

class Image {
	private:
    	std::vector<pixel_t> pixels;
	
	public:
    	Image(std::vector<pixel_t> pixels);

    	std::vector<pixel_t> getPixels();
    	void adjust();
		void print();
		size_t* serialize();
		void process();
};

#endif