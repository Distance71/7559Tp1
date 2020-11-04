#include "Camera.h"

Camera::Camera(resolution_t resolution) {
	this->resolution = resolution;
}

std::vector<pixel_t> Camera::generateImagePixels() {
	srand((unsigned int) time(NULL));
	size_t resolutionLength = this->resolution.width * this->resolution.height;
	std::vector<pixel_t> pixels;

	for(size_t i = 0; i < resolutionLength; i++)
		pixels.push_back(rand() % 256);

	return pixels;
}

Image* Camera::shot() {
	std::vector<pixel_t> pixels = generateImagePixels();
	
	return new Image(pixels);
}