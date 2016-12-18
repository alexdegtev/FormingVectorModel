#include "Convert.hpp"
#include <cmath>

unsigned char FVM::Core::Common::Functions::Convert::rgb2brightness(unsigned char red, unsigned char green, unsigned char blue)
{
	return static_cast<unsigned char>(round(
		0.299 * static_cast<double>(red) +
		0.587 * static_cast<double>(green) +
		0.114 * static_cast<double>(blue)
	));	// From YIQ model.
}

void FVM::Core::Common::Functions::Convert::iimage2mat(Objects::Image::IImage* image, cv::Mat* mat)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			if (mat->channels() == 1)
			{
				mat->at<uchar>(i, j) = image->pixel(i, j)->brightness();
			}
			else
			{
				//многоканальное
				throw;
			}
		}
	}
}


void FVM::Core::Common::Functions::Convert::mat2iimage(cv::Mat *mat, Objects::Image::IImage *image)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			if (mat->channels() == 1)
			{
				Objects::Image::Pixel p(mat->at<uchar>(i, j));
				image->pixel(i, j, &p);
			}
			else
			{
				//многоканальное
				throw;
			}
		}
	}
}