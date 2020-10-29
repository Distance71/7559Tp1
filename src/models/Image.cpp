#include "Image.h"

Image::Image(std::vector<pixel_t> pixels, resolution_t resolution) {
	this->pixels = pixels;
	this->resolution = resolution; 
}

std::vector<pixel_t> Image::getPixels() {
	return this->pixels;
}

void Image::adjust() {
	size_t quantityPixels = this->pixels.size();
	for(size_t i = 0; i < quantityPixels; i++)
		this->pixels[i] += rand() % 256;
}

void Image::print(){
	for(pixel_t pixel : this->pixels)
		std::cout << pixel;

	std::cout << std::endl;
}