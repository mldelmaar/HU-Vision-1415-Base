/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

/**
*	@author Bianca Krieger
*/
#pragma once
#include "IntensityImage.h"
class IntensityImageStudent : public IntensityImage {
public:
	/**  
	*	@brief default constructor
	*/
	IntensityImageStudent();

	/**  
	*	@brief constructor that creates a copy of the image
	*   @param &other image that must be copied
	*/
	IntensityImageStudent(const IntensityImageStudent &other);
	
	/**  
	*	@brief constructor that creates a copy of the image
	*   @param &other image that must be copied
	*/
	IntensityImageStudent(const IntensityImage &other);
	
	/**  
	*	@brief constructor that initializes the pixel storage
	*   @param width of the image to store
	*   @param height of the image to store
	*/
	IntensityImageStudent(const int width, const int height);

	/**  
	*	@brief destuctor that deletes the allocated object
	*/
	~IntensityImageStudent();

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
	void set(const IntensityImageStudent &other);

	/**  
	*	@brief sets the intensity pixel on the given x and y
	*   @param x position of the pixel to set 
	*   @param y position of the pixel to set
	*	@param pixel the intensity of the pixel
	*/
	void setPixel(int x, int y, Intensity pixel);

	/**  
	*	@brief sets the intensity pixel at the given position in the storage
	*   @param i index of the storage
	*	@param pixel the intensity of the pixel
	*/
	void setPixel(int i, Intensity pixel);

	/**  
	*	@brief gets the intensity of the given x and y position
	*   @param x position
	*	@param y position
	*	@return Intensity of the pixel on the given position
	*/
	Intensity getPixel(int x, int y) const;

	/**  
	*	@brief gets the intensity of the given position in the storage
	*   @param i index
	*	@return Intensity of the pixel on the given position
	*/
	Intensity getPixel(int i) const;

	/**  
	*	@brief clears the intensity image to pixels with the max high intensity
	*/
	void clear();

	/**  
	*	@brief clears the intensity image to pixels with the given pixel intensity
	*	@param pixel the intensity to clear the image with
	*/
	void clear(Intensity pixel);

	

private:
	Intensity* storage;
	int storageWidth;
	int storageHeight;
};