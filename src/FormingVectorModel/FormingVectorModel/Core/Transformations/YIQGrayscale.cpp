#include "YIQGrayscale.hpp"
#include "../Objects/Image/Pixel.hpp"
#include "../Objects/Image/IImage.hpp"

void FVM::Core::Transformations::YIQGrayscale::execute(Objects::Image::IImage* image)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Image::Pixel new_pixel(image->pixel(i, j)->brightness());
			image->pixel(i, j, &new_pixel);
		}
	}
}
