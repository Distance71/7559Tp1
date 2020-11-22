#include "ObservatorySimulator.h"

ObservatorySimulator::ObservatorySimulator(size_t quantityCameras, resolution_t camerasResolution) {
    this->observatory = new Observatory(quantityCameras, camerasResolution);
}

int ObservatorySimulator::takePhoto() {
    Logger* logger;
    ErrorHandler *errorHandler;

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
            if(!this->lastPhotoImagesSerialized) {
                errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: takePhoto: error en memoria: ");
                return -1;
            }

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
                if(!this->lastPhotoImagesSerialized) {
                    errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: takePhoto: error en memoria: ");
                    return -1;
                }

                bytesAvailable *= 2;
            }
            memcpy(this->lastPhotoImagesSerialized + bytesUsed, imageSerialized + bytesIterator, sizeof(size_t));
            bytesUsed += sizeof(size_t);
            bytesIterator += sizeof(size_t);
        }
    }

    this->lastPhotoImagesSerializedSize = bytesUsed;
    logger->getInstance()->log("Se han tomado las imagenes con exito");
}

int ObservatorySimulator::processImagesSharedMem() {
    ErrorHandler *errorHandler;
    Logger* logger;

    pid_t procId = fork();

    if (procId == 0) {
        SharedMemory<size_t*> sharedPhoto;
        int resultCode = sharedPhoto.create("/bin/bash", 'A');

        if (resultCode < 0) {
            errorHandler->getInstance()->throwError(GENERIC_ERROR, "Simulator: adjust: son: error en memoria compartida: ");
            return -1;
        }
        
        size_t* adjustedImages = this->observatory->adjustImages(this->lastPhotoImagesSerialized);

        sharedPhoto.write(adjustedImages);
        sleep(1);
        
        std::cout << std::endl;
        sharedPhoto.free();
        logger->getInstance()->log("Se ha terminado el proceso hijo de procesamiento");
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

        this->observatory->combineImages(images);
        
        sharedPhoto.free();
        logger->getInstance()->log("Se ha terminado el proceso padre de procesamiento");
        cout << " Padre : fin del proceso " << endl ;
    }
}

int ObservatorySimulator::processImagesFifos() {
    ErrorHandler *errorHandler;
    Logger* logger;
    pid_t procId = fork();

    if (procId == 0) {
        FifoWrite channel(FILE_FIFO);
        channel.openFifo();
        
        size_t* adjustedImages = this->observatory->adjustImages(this->lastPhotoImagesSerialized);

        channel.writeFifo(adjustedImages, this->lastPhotoImagesSerializedSize) ;
        sleep(1);

        channel.free();
        
        std::cout << " Hijo : fin del proceso " << std::endl;
        logger->getInstance()->log("Se ha terminado el proceso hijo de procesamiento");

    } else {
        FifoRead channel(FILE_FIFO);
        channel.openFifo();

        wait(NULL);

        ssize_t bytesLeidos = channel.readFifo(static_cast < void * >(this->lastPhotoImagesSerialized), this->lastPhotoImagesSerializedSize);

        this->observatory->combineImages(this->lastPhotoImagesSerialized);
        channel.free();

        cout << " Padre : fin del proceso " << endl;
        logger->getInstance()->log("Se ha terminado el proceso padre de procesamiento");
    }
}

void ObservatorySimulator::runSharedMem() {
    Logger *logger;
    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registerHandler(SIGINT, &sigint_handler);
    
    while (sigint_handler.getGracefulQuit() == 0) {
        logger->getInstance()->log("El simulador pasara a tomar las fotos");
        this->takePhoto();
        logger->getInstance()->log("El programa procesara las images");
        this->processImagesSharedMem();
    }

    SignalHandler::destroy();
}

void ObservatorySimulator::runFifos() {
    Logger *logger;
    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registerHandler(SIGINT, &sigint_handler);
    
    while (sigint_handler.getGracefulQuit() == 0) {
        logger->getInstance()->log("El simulador pasara a tomar las fotos");
        this->takePhoto();
        logger->getInstance()->log("El programa procesara las images");
        this->processImagesFifos();
    }

    SignalHandler::destroy();
}