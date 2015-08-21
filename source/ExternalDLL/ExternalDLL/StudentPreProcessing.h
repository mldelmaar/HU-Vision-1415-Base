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


	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;
	IntensityImage * stepThresholding(const IntensityImage &image) const;

private:
	const int MAX_WIDTH = 200;
	const int MAX_HEIGHT = 200;
};