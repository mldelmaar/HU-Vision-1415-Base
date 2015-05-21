#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	 //Throws error without the need to include a header
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :
    RGBImage(other.getWidth(), other.getHeight()) {
	
	//TODO: Create a copy from the other object
	RGBImageStudent copy;
	copy = other;
}


RGBImageStudent::RGBImageStudent(const int width, const int height) :
    RGBImage(width, height) {
	
	//TODO: Initialize pixel storage
        storageWidth  = width;
        storageHeight = height;
        storage = new RGB[storageWidth * storageHeight];
}

RGBImageStudent::~RGBImageStudent() {
	
	//TODO: delete allocated objects
//        for(int i = 0; i < storageWidth; i++){
  //          delete &storage[i];
    //    }
        delete[] storage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage) 
    //  for(int i = 0; i < storageWidth; i++){
    //      delete &storage[i];
    //  }
    delete[] storage;
    storageWidth  = width;
    storageHeight = height;
	storage = new RGB[storageWidth * storageHeight];

}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
        RGB* otherStorage = new RGB[other.getWidth() * other.getHeight()];
        for(int i = 0; i < storageWidth * storageHeight; i++){
                otherStorage[i] = storage[i];
        }
        delete[] storage;
        storage = otherStorage;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {	
	//TODO: no comment needed :)
    setPixel((y * storageWidth + x), pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
    
    // TODO: set pixel i in "Row-Major Order"
    storage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	
	//TODO: no comment needed :)
    return storage[(y * storageWidth + x)];
}

RGB RGBImageStudent::getPixel(int i) const {
	
	//TODO: see setPixel(int i, RGB pixel)
    return storage[i];
}
