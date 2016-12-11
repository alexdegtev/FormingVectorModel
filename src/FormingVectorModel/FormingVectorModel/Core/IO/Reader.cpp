#include "Reader.hpp"
#include "opencv2/opencv.hpp"

template <class T>
FVM::Core::Objects::Image::IImage* FVM::Core::IO::Reader<T>::read(std::string path_to_file)
{
	cv::Mat mat = cv::imread(path_to_file);
	FVM::Core::Objects::Image::IImage *image = new T(mat.rows, mat.cols);
	cv::Vec3b row_pixel;

	for (int i = 0; i < mat.rows; i++)
	{
		for (int j = 0; j < mat.cols; j++)
		{
			row_pixel = mat.at<cv::Vec3b>(i, j);

			FVM::Core::Objects::Image::Pixel pixel(
				row_pixel.val[2],
				row_pixel.val[1],
				row_pixel.val[0]
			);

			image->pixel(i, j, &pixel);
		}
	}

	return image;
}
