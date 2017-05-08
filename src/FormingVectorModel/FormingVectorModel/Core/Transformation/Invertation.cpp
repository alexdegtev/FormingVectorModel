#include "Invertation.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"
#include <climits>

void Core::Transformation::Invertation::execute(Objects::Visual::IImage* image)
{
	for (int i = 0; i < image->rows(); i++)
	{
		for (int j = 0; j < image->cols(); j++)
		{
			Objects::Visual::Color new_color(UCHAR_MAX - image->get(i, j)->brightness());
			image->set(i, j, &new_color);
		}
	}
}
