#include "YIQGrayscalation.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"

void Core::Transformations::YIQGrayscalation::execute(Objects::Visual::IImage* image)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::Color color(image->get(i, j)->brightness());
			image->set(i, j, &color);
		}
	}
}
