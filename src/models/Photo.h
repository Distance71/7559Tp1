#ifndef PHOTO_H
#define PHOTO_H

#include <vector>
#include "Image.h"
#include "types.h"

class Photo {
	private:
		std::vector<Image*> images;

	public:
    	Photo(std::vector<Image*> images);
		
		std::vector<Image*> getImages();
		void adjust();
		void printImages();
};


#endif