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
	Logger* logger;
	ErrorHandler *errorHandler;
	size_t quantityPixels = this->pixels.size();

	logger->getInstance()->log("Se va a serializar una imagen");

	size_t* bufferAux = (size_t *) malloc(sizeof(size_t) + sizeof(pixel_t) * quantityPixels);

	if(!bufferAux) {
		errorHandler->getInstance()->throwError(GENERIC_ERROR, "Image: serialize: error en memoria: ");
		return NULL;
	}

	size_t* bufferIter = bufferAux;

	memcpy(bufferIter, &quantityPixels, sizeof(size_t));
	bufferIter += sizeof(size_t);

	for(size_t i = 0; i < quantityPixels; i++) {
		memcpy(bufferIter, &this->pixels[i], sizeof(size_t));
		bufferIter += sizeof(size_t);
	}

	logger->getInstance()->log("Se serializo una imagen con exito");

	return bufferAux;
}

void Image::process() {
	Logger* logger;
	size_t quantityPixels = this->pixels.size();

	logger->getInstance()->log("La imagen se procesara");
	for(size_t i = 0; i < quantityPixels; i++)
		this->pixels[i]++;
	
	logger->getInstance()->log("La imagen se ha podido procesar");
}