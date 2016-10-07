#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	std::string fileLoc = "unnamed.png";
	Mat img = imread(fileLoc);
	imshow("OG", img);
	waitKey(0);
	
	//CV conversion
	Mat imsv;
	cvtColor(img,imsv, CV_BGR2HSV);
	//imshow("HSV", imsv);

	//splitting
	vector<Mat> channels;
	split(imsv, channels);
	
	//thresholding
	Mat hueOg = channels.at(0).clone();
	Mat lower, upper;
	Mat result;
	
	threshold(hueOg, lower, 1, 255, CV_THRESH_BINARY);
	//imshow("L", lower);
	//waitKey(0);
	threshold(hueOg, upper, 10, 255, CV_THRESH_BINARY_INV);
	//imshow("U", upper);
	//waitKey(0);
	result = lower & upper;
	imshow("Thresh", result);
	waitKey(0);
	
	//contours
	/*Mat cann;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	Canny(fileLoc, cann, 1, 10, 3);
	findContours(cann, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	*/
}
