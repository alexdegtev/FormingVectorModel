#include "Reader.h"
#include "opencv2/opencv.hpp"
#include "../Objects/Visual/Image.h"

Core::Objects::Visual::IImage* Core::IO::Reader::read(std::string path)
{
	cv::Mat mat = cv::imread(path);
	Objects::Visual::IImage* image = new Objects::Visual::Image(mat.rows, mat.cols);
	cv::Vec3b row_color;

	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			row_color = mat.at<cv::Vec3b>(i, j);
			Objects::Visual::Color color(row_color.val[2], row_color.val[1], row_color.val[0]);
			image->set(i, j, &color);
		}
	}

	return image;
}

Core::Objects::Visual::IImage* Core::IO::Reader::read(Path path)
{
	return read(path.full_path());
}
