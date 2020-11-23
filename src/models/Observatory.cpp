#include "Observatory.h"

Observatory::Observatory(size_t quantityCameras, resolution_t resolution) {
    for(size_t i = 0; i < quantityCameras; i++)
        this->cameras.push_back(new Camera(resolution));
}

std::vector<Image*> Observatory::takeImages() {
    std::vector<Image*> images;
    Logger* logger;

    for(auto camera : this->cameras)
        images.push_back(camera->shot());
    
    for(size_t i = 0; i < images.size(); i++) {
        cout << "Image " << i << endl;
        images[i]->print();
    }
    
    logger->getInstance()->log("El observatorio ha tomado las imagenes");
    return images;
}

size_t* Observatory::adjustImages(size_t* &images) {
    size_t iteratorVal = 0;
    size_t quantityImages;
    Logger* logger;

    logger->getInstance()->log("El observatorio ajustara las imagenes");

    memcpy(&quantityImages, images, sizeof(size_t));
    iteratorVal += sizeof(size_t);
    Image* auxImage;
    size_t quantityPixels;

    memcpy(&quantityPixels, images + iteratorVal, sizeof(size_t));

    iteratorVal = 0;

    memcpy(images + iteratorVal, &quantityImages, sizeof(size_t));
    iteratorVal += sizeof(size_t);

    for(size_t i = 0; i < quantityImages; i++) {
        memcpy(images + iteratorVal, &quantityPixels, sizeof(size_t));
        iteratorVal += sizeof(size_t);
        size_t pixel, auxIter;
        std::vector<pixel_t> auxPixels;
        auxIter = iteratorVal;

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(&pixel, images + iteratorVal, sizeof(size_t));
            iteratorVal += sizeof(size_t);
            auxPixels.push_back(pixel);
        }

        Image *auxImage = new Image(auxPixels);

        auxImage->process();

        std::vector<pixel_t> auxPixelsUpdater = auxImage->getPixels();

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(images + auxIter, &auxPixelsUpdater[j], sizeof(size_t));
            auxIter += sizeof(size_t);
        }

        sleep(1);
    }

    logger->getInstance()->log("El observatorio ha podido ajustar las imagenes");
    return images;
}

void Observatory::combineImages(size_t *images) {
    size_t quantityImages, iter = 0;
    Logger* logger;

    logger->getInstance()->log("El observatorio va a combinar las imagenes");

    memcpy(&quantityImages, images, sizeof(size_t));
    iter += sizeof(size_t);

    size_t quantityPixels, pixel;
    
    for(size_t i = 0; i < quantityImages; i++) {
        memcpy(&quantityPixels, images + iter, sizeof(size_t));
        iter += sizeof(size_t);
        cout << "Imagen " << i << endl;

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(&pixel, images + iter, sizeof(size_t));
            iter += sizeof(size_t);
            cout << " Pixel " << j << " " << " " << pixel << endl;
        }
    }

    logger->getInstance()->log("El observatorio ha podido combinar las imagenes");

    return;
}