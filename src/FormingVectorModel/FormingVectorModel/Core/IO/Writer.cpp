#include "Writer.hpp"
#include <opencv2/opencv.hpp>

void FVM::Core::IO::Writer::write(std::string path_to_file, Objects::Image::IImage* image)
{
	cv::Mat mat(image->rows(), image->cols(), CV_8UC3);

	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Image::Pixel pixel = *image->pixel(i, j);
			mat.at<cv::Vec3b>(i, j) = cv::Vec3b(pixel.blue(), pixel.green(), pixel.red());
		}
	}

	cv::imwrite(path_to_file, mat);
}
