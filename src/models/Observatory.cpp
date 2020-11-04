#include "Observatory.h"

Observatory::Observatory(size_t quantityCameras, resolution_t resolution) {
    for(size_t i = 0; i < quantityCameras; i++)
        this->cameras.push_back(new Camera(resolution));
}

std::vector<Image*> Observatory::takeImages() {
    size_t quantityCameras = this->cameras.size();
    std::vector<Image*> images;

    size_t i = 0;
    for(auto camera : this->cameras)
        images.push_back(camera->shot());

    return images;
}

size_t* Observatory::adjustImages(size_t* &images) {
    size_t iteratorVal = 0;
    size_t quantityImages;

    memcpy(&quantityImages, images, sizeof(size_t));
    iteratorVal += sizeof(size_t);
    Image* auxImage;
    size_t quantityPixels;

    memcpy(&quantityPixels, images + iteratorVal, sizeof(size_t));
    size_t sizeImages = (1 + quantityImages) * (1 + quantityPixels) * sizeof(size_t);
    size_t* imagesAux = (size_t*) malloc(sizeImages);

    memcpy(imagesAux, images, sizeof(sizeImages));
    if(!imagesAux)
        return NULL;

    for(size_t i = 0; i < quantityImages; i++) {
        memcpy(&quantityPixels, images + iteratorVal, sizeof(size_t));
        iteratorVal += sizeof(size_t);
        size_t pixel;
        std::vector<pixel_t> auxPixels;

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(&pixel, images + iteratorVal, sizeof(size_t));
            iteratorVal += sizeof(size_t);
            auxPixels.push_back(pixel);
        }

        Image *auxImage = new Image(auxPixels);

        pid_t id = fork();

        if (id == 0) {
            pid_t pid = getpid();

            auxImage->process();

            size_t *auxImageSerialized = auxImage->serialize();
            size_t iteratorUpdater = sizeof(size_t) * (2 + i * quantityPixels);
            size_t pixel;
            std::vector<pixel_t> auxPixelsUpdater = auxImage->getPixels();

            for(size_t j = 0; j < quantityPixels; j++) {
                memcpy(imagesAux + iteratorUpdater, &auxPixelsUpdater[j], sizeof(size_t));
                iteratorUpdater += sizeof(size_t);
            }

            sleep(1);
        }
        else wait(NULL);
    }

    return images;
}

void Observatory::combineImages(size_t *images) {
    size_t quantityImages, iter = 0;

    memcpy(&quantityImages, images, sizeof(size_t));
    iter += sizeof(size_t);
    std::cout << "La cant final imagenes es " << quantityImages << std::endl;

    size_t quantityPixels, pixel;
    
    std::cout << "La cant final pixels es " << quantityImages << std::endl;
    for(size_t i = 0; i < quantityImages; i++) {
        memcpy(&quantityPixels, images + iter, sizeof(size_t));
        iter += sizeof(size_t);
        std::cout << "la cant pixels " << quantityPixels << std::endl;

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(&pixel, images + iter, sizeof(size_t));
            iter += sizeof(size_t);
            std::cout << "el pixel final " << pixel << std::endl;
        }
    }

    return;
}