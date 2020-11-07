#include "Image.h"

Image::Image(std::vector<pixel_t> pixels) {
	this->pixels = pixels;
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

size_t* Image::serialize() {
	size_t quantityPixels = this->pixels.size();

	size_t* bufferAux = (size_t *) malloc(sizeof(size_t) + sizeof(pixel_t) * quantityPixels);

	if(!bufferAux) //TODO: Add log
		return NULL;

	size_t* bufferIter = bufferAux;

	memcpy(bufferIter, &quantityPixels, sizeof(size_t));
	bufferIter += sizeof(size_t);

	for(size_t i = 0; i < quantityPixels; i++) {
		memcpy(bufferIter, &this->pixels[i], sizeof(size_t));
		bufferIter += sizeof(size_t);
	}

	// To debug

	// size_t debugIter = 0, debugPixel;
	// memcpy(&quantityPixels, bufferAux, sizeof(size_t));
	// std::cout << "la cant pixels decod mem " << quantityPixels << std::endl;
	// debugIter += sizeof(size_t);

	// for(size_t i = 0; i < quantityPixels; i++) {
	// 	memcpy(&debugPixel, bufferAux + debugIter, sizeof(size_t));
	// 	std::cout << "el pixel decod mem " << debugPixel << std::endl;
	// 	debugIter += sizeof(size_t);
	// }

	return bufferAux;
}

Image* Image::deserialize(size_t* bytes, size_t quantityPixels) {
    char pixel[sizeof(pixel_t) + 1];

	std::vector<pixel_t> pixels;
	pixel_t auxPixel;

	for(size_t i = 0; i < quantityPixels; i++) {
		memcpy(&auxPixel, bytes + i * sizeof(size_t), sizeof(size_t));
		pixels.push_back(auxPixel);
	}

	return new Image(pixels);
}

void Image::process(){
	size_t quantityPixels = this->pixels.size();
	for(size_t i = 0; i < quantityPixels; i++) {
		//std::cout << "el pixel antes: " << this->pixels[i] << std::endl; 
		this->pixels[i]++;
		//std::cout << "el pixel despues: " << this->pixels[i] << std::endl;
	}
}