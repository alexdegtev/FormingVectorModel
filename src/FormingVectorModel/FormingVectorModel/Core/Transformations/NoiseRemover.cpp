#include "NoiseRemover.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Visual/Color.h"
using namespace Core::Objects::Visual;

Core::Transformations::NoiseRemover::NoiseRemover() : middle_color((IColor::binary_color::turn_on + IColor::binary_color::turn_off) / 2)
{
}

void Core::Transformations::NoiseRemover::execute(Objects::Visual::IImage* image)
{
	for (int i = 1; i < image->rows() - 1; i++)
	{
		for (int j = 1; j < image->cols() - 1; j++)
		{
			IColor* current_color = image->get(i, j);
			if(current_color->brightness() == IColor::binary_color::turn_off)
			{
				std::vector<IColor*> neighbours = image->get_neighbours(i, j);
				if(neighbours.size() >= 5)
				{
					Color color(IColor::binary_color::turn_on);
					image->set(i, j, &color);
				}
			}
			else
			{
				std::vector<IColor*> neighbours = image->get_neighbours(i, j, IColor::binary_color::turn_off);
				if (neighbours.size() == 5)
				{
					Color color(IColor::binary_color::turn_off);
					image->set(i, j, &color);
				}
			}

			//std::vector<IColor*> neighbours = image->get_neighbours(i, j, IColor::binary_color::turn_on);
			//IColor* current_color = image->get(i, j);
			//unsigned char dominant_color = get_dominant_color(neighbours);
			//if(current_color->brightness() != dominant_color && dominant_color != middle_color)
			//{
			//	Color color(dominant_color);
			//	image->set(i, j, &color);
			//}
		}
	}
}

unsigned char Core::Transformations::NoiseRemover::get_dominant_color(std::vector<IColor*> colors)
{
	int turn_on_count = 0, turn_off_count = 0;

	for(auto color:colors)
	{
		if (color->brightness() == IColor::binary_color::turn_on) turn_on_count++;
		else turn_off_count++;
	}

	if (turn_on_count > turn_off_count) return IColor::binary_color::turn_on;
	if (turn_on_count < turn_off_count) return IColor::binary_color::turn_off;
	return middle_color;
}
