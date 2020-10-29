#include "Photo.h"

Photo::Photo(std::vector<Image*> images) {
    this->images = images;
}

std::vector<Image*> Photo::getImages() {
    return this->images;
}

void Photo::adjust() {

}

void Photo::printImages() {
    for(Image* image : this->images)
        image->print();
}