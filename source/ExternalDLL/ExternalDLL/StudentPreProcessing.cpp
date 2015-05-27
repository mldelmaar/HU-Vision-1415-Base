#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent * intensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
	int imageSize = image.getWidth() * image.getHeight();

	for (int i = 0; i < imageSize; i++){
		intensityImage->setPixel(i, image.getPixel(i).g);
	}

	return intensityImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {	
	int imageSize = image.getWidth() * image.getHeight();
	if (imageSize <= 40000){
		IntensityImageStudent * intensityImage = new IntensityImageStudent(image);
		return intensityImage;
	}
	
	int newWidth;
	int newHeight;
	
	if (image.getWidth() > image.getHeight()){
		newWidth = 200;
		newHeight = newWidth * image.getHeight() / image.getWidth();
	}
	else{
		newHeight = 200;
		newWidth = newHeight * image.getWidth() / image.getHeight();
	}
	
	IntensityImageStudent * intensityImage = new IntensityImageStudent(newWidth, newHeight);
	int magic = 200 * newWidth / image.getWidth();
	for (int x = 0; x < newWidth; x++){
		for (int y = 0; y < newHeight; y++){
			intensityImage->setPixel(x, y, image.getPixel((x * 200) / magic, (y * 200) / magic));
		}
	}
	return intensityImage;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}