#include "ObservatorySimulator.h"

ObservatorySimulator::ObservatorySimulator(size_t quantityCameras, resolution_t camerasResolution) {
    this->observatory = new Observatory(quantityCameras, camerasResolution);
}

int ObservatorySimulator::takePhoto() {
    Logger* logger;
    ErrorHandler *errorHandler;

    logger->getInstance()->log("Se va a simular el observatorio");
    std::vector<Image*> images = this->observatory->takeImages();

    size_t quantityImages = images.size();
    size_t bytesAvailable = INIT_SIZE * sizeof(size_t), bytesUsed = 0;
    this->lastPhotoImagesSerialized = (size_t*) malloc(bytesAvailable);

    if(!this->lastPhotoImagesSerialized) {
        errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: takePhoto: error en memoria: ");
        return -1;
    }

    memcpy(this->lastPhotoImagesSerialized, &quantityImages, sizeof(size_t));
    bytesUsed += sizeof(size_t);

    for(size_t i = 0; i < quantityImages; i++) {
        size_t* imageSerialized = images[i]->serialize();
        size_t auxQuantityPixels;

        if((bytesUsed + sizeof(size_t)) >= bytesAvailable) {
            this->lastPhotoImagesSerialized = (size_t*) realloc(this->lastPhotoImagesSerialized, bytesAvailable * 2);
            if(!this->lastPhotoImagesSerialized) //TODO: add log
                return -1;

            bytesAvailable *= 2;
        }

        memcpy(this->lastPhotoImagesSerialized + bytesUsed, imageSerialized, sizeof(size_t));
        bytesUsed += sizeof(size_t);

        memcpy(&auxQuantityPixels, imageSerialized, sizeof(size_t));
        
        for(size_t i = 0; i < auxQuantityPixels; i++) {
            if((bytesUsed + sizeof(size_t)) >= bytesAvailable) {
                this->lastPhotoImagesSerialized = (size_t*) realloc(this->lastPhotoImagesSerialized, bytesAvailable * 2);
                if(!this->lastPhotoImagesSerialized) //TODO: add log
                    return -1;

                bytesAvailable *= 2;
            }
            memcpy(this->lastPhotoImagesSerialized + bytesUsed, imageSerialized + (i + 1) * sizeof(size_t), sizeof(size_t));
            bytesUsed += sizeof(size_t);
        }
    }

    //Debug

    size_t debug[31];
    for(size_t i = 0; i < 31; i++) {
        memcpy(&debug[i], this->lastPhotoImagesSerialized + i * sizeof(size_t), sizeof(size_t));
        cout << "el dato decod take photo " << debug[i] << endl;
    }
}

int ObservatorySimulator::processImages() {
    ErrorHandler *errorHandler;

    pid_t procId = fork();

    if (procId == 0) {
        SharedMemory<size_t*> sharedPhoto;
        int resultCode = sharedPhoto.create("/bin/bash", 'A');

        if (resultCode < 0) {
            errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: adjust: father: error en memoria compartida: ");
            return -1;
        }
        sleep(3);
        size_t* images = sharedPhoto.read();

        size_t* adjustedImages = this->observatory->adjustImages(images);

        sharedPhoto.write(adjustedImages);
        
        std::cout << std::endl;
        std::cout << " Hijo : fin del proceso " << std::endl ;

    } else {
        SharedMemory<size_t*> sharedPhoto;
        int resultCode = sharedPhoto.create("/bin/bash", 'A');

        if (resultCode < 0) {
            errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: adjust: father: error en memoria compartida: ");
            return -1;
        }

        sharedPhoto.write(this->lastPhotoImagesSerialized);

        wait(NULL);

        size_t* images = sharedPhoto.read();

        this->observatory->combineImages(images);        
        
        sharedPhoto.free();
        cout << " Padre : fin del proceso " << endl ;
    }
}

void ObservatorySimulator::run() {
    this->takePhoto();
    
    this->processImages();
}