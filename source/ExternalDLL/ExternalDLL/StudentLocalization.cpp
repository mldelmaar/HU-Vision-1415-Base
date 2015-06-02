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

	for (int x = 0; x < image.getWidth(); x++) {
		for (int y = startY; y < maxY; y++){
			if (image.getPixel(x, y) == 0){
				histogram[x]++;
			}
		}
	}

	return histogram;
}

/*int ** StudentLocalization::getFaceHistograms(const IntensityImage &image, int alpha) {
	int y = getTopOfHead(image);
	int count = ((image.getHeight() - y - 1) / alpha) + 1;
	int ** histograms = new int*[count];

	for (int i = 0; i < count; i++) {
		histograms[i] = getHistogramX(image, alpha, y + i * alpha);
	}
}*/

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
		if (histogram[x] > threshold){
			subsequentEdge++;
		}
		else{
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

	int count = ((image.getHeight() - yTop - 1) / alpha) + 1;

	for (int i = 0; i < count; i++) {
		histogram = getHistogramX(image, alpha, yTop + i * alpha);
		findSidesInHistogram(histogram, image.getWidth(), &left, &right);
		if (left == -1 || right == -1) {
			continue;
		}

		diffFirstLast = right - left;
		if (diffFirstLast > maxDiffFirstLast) {
			maxDiffFirstLast = diffFirstLast;
		}
		else {
			ySides = yTop + (i + 1)  * alpha;
			break;
		}
	}

	if (ySides == -1) {
		return false;
	}

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