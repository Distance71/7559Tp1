#include "ObservatorySimulator.h"

ObservatorySimulator::ObservatorySimulator(size_t quantityCameras, resolution_t camerasResolution) {
    this->observatory = new Observatory(quantityCameras, camerasResolution);
}

void ObservatorySimulator::takePhoto() {
    Photo* photo = this->observatory->takePhoto();

    photo->printImages(); //Erase
}

void ObservatorySimulator::run() {
    this->takePhoto();
    
    // this->adjust();

    // this->plainImages();
}