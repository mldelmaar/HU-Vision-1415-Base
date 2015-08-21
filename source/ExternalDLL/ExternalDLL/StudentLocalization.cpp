#include "StudentLocalization.h"

int * StudentLocalization::getHistogramX(const IntensityImage &image, int alpha, int startY) {
	int * histogram = new int[image.getWidth()];

	// Make array filled with zero's
	std::fill_n(histogram, image.getWidth(), 0);

	// Calculate max Y
	int maxY = startY + alpha;
	if (maxY > image.getHeight()) {
		maxY = image.getHeight();
	}

	//counts for a certain vertical range the amount 
	//of pixels on every x location that have a low intensity(black)
	for (int x = 0; x < image.getWidth(); x++) {
		for (int y = startY; y < maxY; y++){
			if (image.getPixel(x, y) == 0){
				histogram[x]++;
			}
		}
	}

	return histogram;
}


int StudentLocalization::getTopOfHead(const IntensityImage &image){
	for (int y = 0; y < image.getHeight(); y++){
		for (int x = 0; x < image.getWidth(); x++) {
			if (image.getPixel(x, y) == 0){
				return y;
			}
		}
	}
	return -1;
}

void StudentLocalization::findSidesInHistogram(int* histogram, int size, int* first, int * last){
	int threshold = 4;
	int subsequentEdge = 0;
	int subsequentThreshold = 2;
	*first = -1;
	*last = -1;

	for (int x = 0; x < size; x++){
		//if the histogram value is above the threshold a potential side is detected
		//the number of subsequent edges is counted to find out the thickness of a potential edge
		//to determine whether or not it is a real edge
		if (histogram[x] > threshold){
			subsequentEdge++;
		}
		else{
			//if the end of a edge is detected determine by the value of the subsequentEdge 
			//whether or not it should be counted as a real edge and stored in either the first
			// or last variable. The first variable will be filled in once and the last variable will
			//be overwritten everytime a new edge is detected
			if (subsequentEdge > subsequentThreshold){
				if (*first == -1){
					*first = x - (subsequentEdge / 2);
				}
				else{
					*last = x - (subsequentEdge / 2);
				}
			}
			subsequentEdge = 0;
		}
	}
}

bool StudentLocalization::stepFindHead(const IntensityImage &image, FeatureMap &features) const {
	int yTop = getTopOfHead(image);
	int alpha = 13;
	int* histogram;
	int left, right;
	int diffFirstLast = -1, maxDiffFirstLast = -1;
	int ySides = -1;
	//number of slices the image will be 'cut' into for the histograms
	int count = ((image.getHeight() - yTop - 1) / alpha) + 1;

	for (int i = 0; i < count; i++) {
		//get histogram of current slice
		histogram = getHistogramX(image, alpha, yTop + i * alpha);
		findSidesInHistogram(histogram, image.getWidth(), &left, &right);
		//if no two sides have been found continue to the next slice
		if (left == -1 || right == -1) {
			continue;
		}

		//find the first peak gap between the left and right side to detect the position of the ears
		diffFirstLast = right - left;
		if (diffFirstLast > maxDiffFirstLast) {
			maxDiffFirstLast = diffFirstLast;
		}
		else {
			//if the gap is lower than the max, a peak has been found
			//and the y position of the ears will be set to the middle of the slice 
			//where the peak is detected
			ySides = yTop + (i + 1)  * alpha;
			break;
		}
	}
	//if no peak is detected return false
	if (ySides == -1) {
		return false;
	}

	//set the results in the feature map
	Point2D<double> * pointLeftSideHead = new Point2D<double>(left, ySides);
	Feature * leftSideHead = new Feature(Feature::FEATURE_HEAD_LEFT_SIDE, *pointLeftSideHead);
	features.putFeature(*leftSideHead);

	Point2D<double> * pointRightSideHead = new Point2D<double>(right, ySides);
	Feature * rightSideHead = new Feature(Feature::FEATURE_HEAD_RIGHT_SIDE, *pointRightSideHead);
	features.putFeature(*rightSideHead);

	Point2D<double> * pointTopOfHead = new Point2D<double>((left + right) / 2, yTop);
	Feature * topOfHead = new Feature(Feature::FEATURE_HEAD_TOP, *pointTopOfHead);
	features.putFeature(*topOfHead);
	
	return true;
}

bool StudentLocalization::stepFindNoseMouthAndChin(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindChinContours(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindNoseEndsAndEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}

bool StudentLocalization::stepFindExactEyes(const IntensityImage &image, FeatureMap &features) const {
	return false;
}