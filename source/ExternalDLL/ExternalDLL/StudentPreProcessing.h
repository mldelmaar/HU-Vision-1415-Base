/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/


/**
*	@author Bianca Krieger
*	@author Marianne Delmaar
*/
#pragma once
#include "PreProcessing.h"
#include "IntensityImageStudent.h"
class StudentPreProcessing : public PreProcessing {
public:
	/** 
	*	@brief converts a RGB image into a intensity image using only the
	*		   green value of the RGB pixels 
	*	@param &image to be converted into a intensity image
	*/
	IntensityImage * stepToIntensityImage(const RGBImage &image) const;

	/**
	*	@brief resizes the image to an image of 200x200
	*	@param &image to be resized into a image of 200x200
	*/
	IntensityImage * stepScaleImage(const IntensityImage &image) const;

	/**
	*	@brief detects the edges by applying a laplacian filter
	*	@param &image from which the edges wil be detected 
	*/
	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;

	/**
	*	@brief changes the pixels into black or white depending on whether the value of
	*		   the pixel is under or above the threshold
	*	@param &image where the pixels will be converted 
	*	@return IntensityImage image with only black and white values 
	*/
	IntensityImage * stepThresholding(const IntensityImage &image) const;

private:
	const int MAX_WIDTH = 200;
	const int MAX_HEIGHT = 200;
};