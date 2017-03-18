#include "OtsuBinarization.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"

void Core::Transformations::OtsuBinarization::execute(Objects::Visual::IImage* image)
{
	unsigned char t = threshold(image);

	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::Color color(
				image->get(i, j)->brightness() > t ?
					Objects::Visual::IColor::binary_color::turn_on :
					Objects::Visual::IColor::binary_color::turn_off
			);
			image->set(i, j, &color);
		}
	}
}

unsigned char Core::Transformations::OtsuBinarization::threshold(Objects::Visual::IImage* image)
{
	//TODO: Добавить реализацию
	throw "method is not implemented";
}
