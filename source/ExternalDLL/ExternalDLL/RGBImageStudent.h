/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

/*
*	@author Bianca Krieger
*/
#pragma once
#include "RGBImage.h"
class RGBImageStudent : public RGBImage {
public:
	/**
	*	@brief default constructor
	*/
	RGBImageStudent();

	/**
	*	@brief constructor that creates a copy of the image
	*   @param &other image that must be copied
	*/
	RGBImageStudent(const RGBImageStudent &other);

	/**
	*	@brief constructor that initializes the pixel storage
	*   @param width of the image to store
	*   @param height of the image to store
	*/
	RGBImageStudent(const int width, const int height);

	/**
	*	@brief destuctor that deletes the allocated object
	*/
	~RGBImageStudent();
	
	/**
	*	@brief creates a new pixel storage with the given width and height
	*   @param width of the image to store
	*   @param height of the image to store
	*/
	void set(const int width, const int height);

	/**
	*	@brief creates a new pixel storage with the size of the other
	*		   and copies the pixels from the original image
	*   @param &other the image to copy
	*/
	void set(const RGBImageStudent &other);

	/**
	*	@brief sets the pixel on the given x and y
	*   @param x position of the pixel to set
	*   @param y position of the pixel to set
	*	@param pixel the intensity of the pixel
	*/
	void setPixel(int x, int y, RGB pixel);

	/**
	*	@brief sets the pixel at the given position in the storage
	*   @param i index of the storage
	*	@param pixel the intensity of the pixel
	*/
	void setPixel(int i, RGB pixel);

	/**
	*	@brief gets the pixel of the given x and y position
	*   @param x position
	*	@param y position
	*	@return RGB of the pixel on the given position
	*/
	RGB getPixel(int x, int y) const;

	/**
	*	@brief gets the pixel of the given position in the storage
	*   @param i index
	*	@return RGB of the pixel on the given position
	*/
	RGB getPixel(int i) const;

private:
        RGB* storage;
        int storageWidth;
        int storageHeight;
};
