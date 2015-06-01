#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	 //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : 
	IntensityImage(other.getWidth(), other.getHeight()) {
	//TODO: Create a copy from the other object
	IntensityImageStudent copy;
	copy = other;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImage &other) :
IntensityImage(other.getWidth(), other.getHeight()) {
	//TODO: Create a copy from the other object
	IntensityImageStudent copy;
	copy = other;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	//TODO: Initialize pixel storage
	storageWidth = width;
	storageHeight = height;
	storage = new Intensity[storageWidth * storageHeight];
}

IntensityImageStudent::~IntensityImageStudent() {
	//TODO: delete allocated objects
	delete[] storage;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	delete[] storage;
	storageWidth = width;
	storageHeight = height;
	storage = new Intensity[storageWidth * storageHeight];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	Intensity* otherStorage = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < storageWidth * storageHeight; i++){
		otherStorage[i] = storage[i];
	}
	delete[] storage;
	storage = otherStorage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//TODO: no comment needed :)
	setPixel((y * storageWidth + x), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	storage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return storage[(y * storageWidth + x)];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return storage[i];
}

void IntensityImageStudent::clear(Intensity pixel) {
	std::fill_n(storage, storageWidth * storageHeight, pixel);
}

void IntensityImageStudent::clear() {
	clear(255);
}