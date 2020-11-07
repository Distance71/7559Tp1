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

        size_t bytesIterator = 0;

        memcpy(this->lastPhotoImagesSerialized + bytesUsed, imageSerialized + bytesIterator, sizeof(size_t));
        bytesUsed += sizeof(size_t);

        memcpy(&auxQuantityPixels, imageSerialized + bytesIterator, sizeof(size_t));
        bytesIterator += sizeof(size_t);

        for(size_t i = 0; i < auxQuantityPixels; i++) {
            if((bytesUsed + sizeof(size_t)) >= bytesAvailable) {
                this->lastPhotoImagesSerialized = (size_t*) realloc(this->lastPhotoImagesSerialized, bytesAvailable * 2);
                if(!this->lastPhotoImagesSerialized) //TODO: add log
                    return -1;

                bytesAvailable *= 2;
            }
            memcpy(this->lastPhotoImagesSerialized + bytesUsed, imageSerialized + bytesIterator, sizeof(size_t));
            bytesUsed += sizeof(size_t);
            bytesIterator += sizeof(size_t);
        }
    }

    size_t debug[31];
    for(size_t i = 0; i < 31; i++) {
        memcpy(&debug[i], this->lastPhotoImagesSerialized + i * sizeof(size_t), sizeof(size_t));
        cout << "el dato inicial" << i << " valor " << debug[i] << endl;
    }

    this->lastPhotoImagesSerializedSize = bytesUsed;
}

int ObservatorySimulator::processImagesSharedMem() {
    ErrorHandler *errorHandler;

    

    pid_t procId = fork();

    if (procId == 0) {
        SharedMemory<size_t*> sharedPhoto;
        int resultCode = sharedPhoto.create("/bin/bash", 'A');

        if (resultCode < 0) {
            errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: adjust: son: error en memoria compartida: ");
            return -1;
        }
        
        size_t* adjustedImages = this->observatory->adjustImages(this->lastPhotoImagesSerialized);
        size_t iteratorValDebug = 0;

        iteratorValDebug += sizeof(size_t);

        // size_t debug[31];
        // for(size_t i = 0; i < 31; i++) {
        //     memcpy(&debug[i], adjustedImages + i * sizeof(size_t), sizeof(size_t));
        //     cout << "el dato adjusted" << i << " valor " << debug[i] << endl;
        // }

        sharedPhoto.write(adjustedImages);
        sleep(1);
        
        std::cout << std::endl;
        sharedPhoto.free();
        std::cout << " Hijo : fin del proceso " << std::endl;

    } else {
        SharedMemory<size_t*> sharedPhoto;
        int resultCode = sharedPhoto.create("/bin/bash", 'A');

        if (resultCode < 0) {
            errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: adjust: father: error en memoria compartida: ");
            return -1;
        }

        wait(NULL);

        size_t* images = sharedPhoto.read();

        // size_t debug[31];
        // for(size_t i = 0; i < 31; i++) {
        //     memcpy(&debug[i], images + i * sizeof(size_t), sizeof(size_t));
        //     cout << "el dato final" << i << " valor " << debug[i] << endl;
        // }

        this->observatory->combineImages(images);
        
        sharedPhoto.free();
        cout << " Padre : fin del proceso " << endl ;
    }
}

int ObservatorySimulator::processImagesFifos() {
    ErrorHandler *errorHandler;

    pid_t procId = fork();

    if (procId == 0) {
        FifoWrite channel(FILE_FIFO);
        channel.openFifo();
        
        size_t* adjustedImages = this->observatory->adjustImages(this->lastPhotoImagesSerialized);
        size_t iteratorValDebug = 0;

        iteratorValDebug += sizeof(size_t);

        size_t debug[31];
        for(size_t i = 0; i < 31; i++) {
            memcpy(&debug[i], adjustedImages + i * sizeof(size_t), sizeof(size_t));
            cout << "el dato adjusted" << i << " valor " << debug[i] << endl;
        }

        channel.writeFifo(adjustedImages, this->lastPhotoImagesSerializedSize) ;
        sleep(1);

        channel.free();
        
        std::cout << " Hijo : fin del proceso " << std::endl;

    } else {
        FifoRead channel(FILE_FIFO);
        channel.openFifo();

        wait(NULL);

        ssize_t bytesLeidos = channel.readFifo(static_cast < void * >(this->lastPhotoImagesSerialized), this->lastPhotoImagesSerializedSize);

        size_t debug[31];
        for(size_t i = 0; i < 31; i++) {
            memcpy(&debug[i], this->lastPhotoImagesSerialized + i * sizeof(size_t), sizeof(size_t));
            cout << "el dato final" << i << " valor " << debug[i] << endl;
        }

        this->observatory->combineImages(this->lastPhotoImagesSerialized);
        channel.free();

        cout << " Padre : fin del proceso " << endl ;
    }
}

void ObservatorySimulator::runSharedMem() {
    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registerHandler(SIGINT, &sigint_handler);
    
    while (sigint_handler.getGracefulQuit() == 0) {
        this->takePhoto();
        this->processImagesSharedMem();
    }

    SignalHandler::destroy();
}

void ObservatorySimulator::runFifos() {
    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registerHandler(SIGINT, &sigint_handler);
    
    while (sigint_handler.getGracefulQuit() == 0) {
        this->takePhoto();
        this->processImagesFifos();
    }

    SignalHandler::destroy();
}