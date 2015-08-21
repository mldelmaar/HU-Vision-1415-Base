#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) :
    RGBImage(other.getWidth(), other.getHeight()) {
	RGBImageStudent copy;
	copy = other;
}


RGBImageStudent::RGBImageStudent(const int width, const int height) :
    RGBImage(width, height) {
        storageWidth  = width;
        storageHeight = height;
        storage = new RGB[storageWidth * storageHeight];
}

RGBImageStudent::~RGBImageStudent() {
        delete[] storage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
    delete[] storage;
    storageWidth  = width;
    storageHeight = height;
	storage = new RGB[storageWidth * storageHeight];

}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());

    RGB* otherStorage = new RGB[other.getWidth() * other.getHeight()];
    for(int i = 0; i < storageWidth * storageHeight; i++){
		otherStorage[i] = storage[i];
    }
    delete[] storage;
    storage = otherStorage;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {	
    setPixel((y * storageWidth + x), pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
    storage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
    return storage[(y * storageWidth + x)];
}

RGB RGBImageStudent::getPixel(int i) const {
    return storage[i];
}
