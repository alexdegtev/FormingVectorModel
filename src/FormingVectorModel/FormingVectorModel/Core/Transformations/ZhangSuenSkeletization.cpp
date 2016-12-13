#include "ZhangSuenSkeletization.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "../CommonFunctions/Convert.hpp"

//#include "../include/ZhangSuenSkeletization.hpp"
//#include <opencv2/imgproc/imgproc.hpp>
//#include "../../CommonFunctions/include/Convertation.hpp"
//
//
//void RDO::Transformations::ZhangSuenSkeletization::execute(Objects::Image::IImage* image)
//{
//	cv::Mat skeleton(image->rows(), image->cols(), CV_8UC1);
//	CommonFunctions::Convertation::iimage2mat(image, &skeleton);
//
//	//cv::Mat bw;
//	//cv::cvtColor(skeleton, skeleton, CV_BGR2GRAY);
//	//cv::threshold(skeleton, bw, 10, 255, CV_THRESH_BINARY);
//
//	thinning(skeleton);
//
//	CommonFunctions::Convertation::mat2iimage(&skeleton, image);
//}
//
//void RDO::Transformations::ZhangSuenSkeletization::thinning(cv::Mat& im)
//{
//	im /= 255;
//
//	cv::Mat prev = cv::Mat::zeros(im.size(), CV_8UC1);
//	cv::Mat diff;
//
//	do {
//		thinning_iteration(im, 0);
//		thinning_iteration(im, 1);
//		cv::absdiff(im, prev, diff);
//		im.copyTo(prev);
//	} while (cv::countNonZero(diff) > 0);
//
//	im *= 255;
//}
//
//void RDO::Transformations::ZhangSuenSkeletization::thinning_iteration(cv::Mat& im, int iter)
//{
//	cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);
//
//	for (int i = 1; i < im.rows - 1; i++)
//	{
//		for (int j = 1; j < im.cols - 1; j++)
//		{
//			uchar p2 = im.at<uchar>(i - 1, j);
//			uchar p3 = im.at<uchar>(i - 1, j + 1);
//			uchar p4 = im.at<uchar>(i, j + 1);
//			uchar p5 = im.at<uchar>(i + 1, j + 1);
//			uchar p6 = im.at<uchar>(i + 1, j);
//			uchar p7 = im.at<uchar>(i + 1, j - 1);
//			uchar p8 = im.at<uchar>(i, j - 1);
//			uchar p9 = im.at<uchar>(i - 1, j - 1);
//
//			int A = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
//				(p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
//				(p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
//				(p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
//			int B = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
//			int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
//			int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);
//
//			if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
//				marker.at<uchar>(i, j) = 1;
//		}
//	}
//
//	im &= ~marker;
//}
void FVM::Core::Transformations::ZhangSuenSkeletization::execute(Objects::Image::IImage* image)
{
	cv::Mat skeleton(image->rows(), image->cols(), CV_8UC1);
	CommonFunctions::Convert::iimage2mat(image, &skeleton);
	
	thinning(skeleton);
	
	CommonFunctions::Convert::mat2iimage(&skeleton, image);
}

void FVM::Core::Transformations::ZhangSuenSkeletization::thinning(cv::Mat& im)
{
	im /= 255;
	
	cv::Mat prev = cv::Mat::zeros(im.size(), CV_8UC1);
	cv::Mat diff;
	
	do {
		thinning_iteration(im, 0);
		thinning_iteration(im, 1);
		cv::absdiff(im, prev, diff);
		im.copyTo(prev);
	} while (cv::countNonZero(diff) > 0);
	
	im *= 255;
}

void FVM::Core::Transformations::ZhangSuenSkeletization::thinning_iteration(cv::Mat& im, int iter)
{
	cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);
	
	for (int i = 1; i < im.rows - 1; i++)
	{
		for (int j = 1; j < im.cols - 1; j++)
		{
			uchar p2 = im.at<uchar>(i - 1, j);
			uchar p3 = im.at<uchar>(i - 1, j + 1);
			uchar p4 = im.at<uchar>(i, j + 1);
			uchar p5 = im.at<uchar>(i + 1, j + 1);
			uchar p6 = im.at<uchar>(i + 1, j);
			uchar p7 = im.at<uchar>(i + 1, j - 1);
			uchar p8 = im.at<uchar>(i, j - 1);
			uchar p9 = im.at<uchar>(i - 1, j - 1);
	
			int A = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
				(p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
				(p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
				(p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
			int B = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
			int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
			int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);
	
			if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
				marker.at<uchar>(i, j) = 1;
		}
	}
	
	im &= ~marker;
}
