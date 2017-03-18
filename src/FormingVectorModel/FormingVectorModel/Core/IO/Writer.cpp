#include "Writer.h"
#include "opencv2/opencv.hpp"
#include "../Objects/Visual/Color.h"

void Core::IO::Writer::write(std::string path, Objects::Visual::IImage* image)
{
	cv::Mat mat(image->rows(), image->cols(), CV_8UC3);

	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::IColor* color = image->get(i, j);
			mat.at<cv::Vec3b>(i, j) = cv::Vec3b(color->blue(), color->green(), color->red());
		}
	}

	cv::imwrite(path, mat);
}

void Core::IO::Writer::write(Path path, Objects::Visual::IImage* image)
{
	write(path.full_path(), image);
}
