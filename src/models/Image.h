#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>
#include <string.h>
#include "types.h"

class Image {
	private:
    	std::vector<pixel_t> pixels;
	
	public:
    	Image(std::vector<pixel_t> pixels);

    	std::vector<pixel_t> getPixels();
    	void adjust();
		void print();
		static Image* deserialize(size_t* bytes, size_t quantityPixels);
		size_t* serialize();
		void process();
};

#endif