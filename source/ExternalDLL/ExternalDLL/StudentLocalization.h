/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

/**
* @Author Bianca Krieger 
*/
#pragma once
#include "Localization.h"
#include "IntensityImageStudent.h"
#include "Feature.h"
#include "Point2D.h"

class StudentLocalization :
	public Localization {
public:

	bool stepFindHead(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindChinContours(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const;
	bool stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const;
	
	/** @brief counts for a certain vertical range, from y to y + alpha, the amount 
	*		   of pixels on every x location that have a low intensity (black)
	*   @param &image a reference to the intensity image 
	*   @param alpha the height range
	*   @param startY the top if the y in the range
	*	@return histogram a array of the amount the low intensity pixels for 
	*			every x position within the given y range
	*/
	static int * getHistogramX(const IntensityImage &image, int alpha, int startY);

	/** @brief detects the left and right sides in the histogram which are above 
	*		   certain thresholds.
	*   @param *histogram to find the sides in
	*   @param size of the histgram and also the width of the image
	*   @param *first side that is found in the histogram
	*	@param *last side that is found in the histogram
	*/
	static void findSidesInHistogram(int* histogram, int size, int* first, int * last);

	/** @brief detects the first low intensity pixel starting from the upper left corner
	*          of the image which indicates the top of the head  
	*   @param &image a reference to the intensity image
	*	@return the y of the first low intensity pixel		
	*/
	static int getTopOfHead(const IntensityImage &image);
};

