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

void Observatory::adjustImages() {}
void Observatory::combineImages() {}

Photo* Observatory::takePhoto(){
    std::vector<Image*> images = this->takeImages();

    Photo* lastPhoto = new Photo(images);
    this->lastPhoto = lastPhoto;
    return lastPhoto;
}