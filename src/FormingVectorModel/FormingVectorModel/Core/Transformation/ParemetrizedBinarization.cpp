#include "ParemetrizedBinarization.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"

Core::Transformation::ParemetrizedBinarization::ParemetrizedBinarization(int threshold) : threshold_(threshold)
{
}

void Core::Transformation::ParemetrizedBinarization::execute(Objects::Visual::IImage* image)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::Color color(
				image->get(i, j)->brightness() > threshold_ ?
				Objects::Visual::IColor::binary_color::turn_on :
				Objects::Visual::IColor::binary_color::turn_off
			);
			image->set(i, j, &color);
		}
	}
}
