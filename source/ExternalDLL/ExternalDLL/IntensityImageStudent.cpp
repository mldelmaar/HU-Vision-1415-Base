#include "IntensityImageStudent.h"
#include <iostream>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : 
	IntensityImage(other.getWidth(), other.getHeight()) {
	int size = other.getHeight() * other.getWidth();
	this->set(other.getHeight(), other.getWidth());
	
	for (int i = 0; i < size; i++){
		this->setPixel(i, other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const IntensityImage &other) :
	IntensityImage(other.getWidth(), other.getHeight()) {
	int size = other.getHeight() * other.getWidth();
	this->set(other.getHeight(), other.getWidth());
	
	for (int i = 0; i < size; i++){
		this->setPixel(i, other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	storageWidth = width;
	storageHeight = height;
	storage = new Intensity[storageWidth * storageHeight];
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] storage;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] storage;

	storageWidth = width;
	storageHeight = height;
	storage = new Intensity[storageWidth * storageHeight];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	Intensity* otherStorage = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < storageWidth * storageHeight; i++){
		otherStorage[i] = storage[i];
	}
	delete[] storage;
	storage = otherStorage;
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	setPixel((y * storageWidth + x), pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	storage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return storage[(y * storageWidth + x)];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return storage[i];
}

void IntensityImageStudent::clear(Intensity pixel) {
	std::fill_n(storage, storageWidth * storageHeight, pixel);
}

void IntensityImageStudent::clear() {
	clear(255);
}