#include "MiddleThresholdBinarization.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"

void Core::Transformations::MiddleThresholdBinarization::execute(Objects::Visual::IImage* image)
{
	unsigned char t = 128;

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
