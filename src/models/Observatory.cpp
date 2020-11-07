#include "Observatory.h"

Observatory::Observatory(size_t quantityCameras, resolution_t resolution) {
    for(size_t i = 0; i < quantityCameras; i++)
        this->cameras.push_back(new Camera(resolution));
}

std::vector<Image*> Observatory::takeImages() {
    std::vector<Image*> images;

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

    // //Debug

    // size_t debug[31];
    // for(size_t i = 0; i < 31; i++) {
    //     memcpy(&debug[i], images + i * sizeof(size_t), sizeof(size_t));
    //     std::cout << "el dato decod take photo " << i << " valor " << debug[i] << std::endl;
    // }

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
            //std::cout << "el valor iter " << iteratorVal << std::endl;
            memcpy(&pixel, images + iteratorVal, sizeof(size_t));
            iteratorVal += sizeof(size_t);
            auxPixels.push_back(pixel);
            //std::cout << "El pixel " << pixel << std::endl;
        }

        Image *auxImage = new Image(auxPixels);

        // std::cout << "Se va a mostrar la imagen previa " << i << std::endl;
        // auxImage->print();
        auxImage->process();

        // std::cout << "Se va a mostrar la imagen " << i << std::endl;
        // auxImage->print();

        std::vector<pixel_t> auxPixelsUpdater = auxImage->getPixels();

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(images + auxIter, &auxPixelsUpdater[j], sizeof(size_t));
            auxIter += sizeof(size_t);
        }

        sleep(1);
    }

    return images;
}

void Observatory::combineImages(size_t *images) {
    size_t quantityImages, iter = 0;

    memcpy(&quantityImages, images, sizeof(size_t));
    iter += sizeof(size_t);
    //std::cout << "La cant final imagenes es " << quantityImages << std::endl;

    size_t quantityPixels, pixel;
    
    //std::cout << "La cant final pixels es " << quantityImages << std::endl;
    for(size_t i = 0; i < quantityImages; i++) {
        memcpy(&quantityPixels, images + iter, sizeof(size_t));
        iter += sizeof(size_t);
        //std::cout << "la cant pixels " << quantityPixels << std::endl;

        for(size_t j = 0; j < quantityPixels; j++) {
            memcpy(&pixel, images + iter, sizeof(size_t));
            iter += sizeof(size_t);
            //std::cout << "el pixel final " << pixel << std::endl;
        }
    }

    return;
}