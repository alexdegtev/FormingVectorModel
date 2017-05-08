#include "SingleNoisePointsRemover.h"
#include "../Objects/Visual/IImage.h"
#include "../Common/Functions.h"

void Core::Transformations::SingleNoisePointsRemover::execute(Objects::Visual::IImage* image)
{
	for (int i = 0; i < image->rows(); ++i)
	{
		for (int j = 0; j < image->cols(); ++j)
		{
			std::vector<Objects::Visual::IColor*> neighbours = Common::Functions::get_all_neighbours(i, j, image);

			// Removing noise objects pixels
			if (image->get(i, j)->brightness() == Objects::Visual::IColor::binary_color::turn_on)
			{
				bool is_all_neighbours_turn_off = true;
				for (auto n : neighbours)
				{
					if(n->brightness() == Objects::Visual::IColor::binary_color::turn_on && is_all_neighbours_turn_off)
					{
						is_all_neighbours_turn_off = false;
					}
				}

				if(is_all_neighbours_turn_off)
				{
					image->get(i, j)->brightness(Objects::Visual::IColor::binary_color::turn_off);
				}
			}
			// Removing noise backgroud pixels
			else
			{
				bool is_all_neighbours_turn_on = true;
				for (auto n : neighbours)
				{
					if (n->brightness() == Objects::Visual::IColor::binary_color::turn_off && is_all_neighbours_turn_on)
					{
						is_all_neighbours_turn_on = false;
					}
				}

				if (is_all_neighbours_turn_on)
				{
					image->get(i, j)->brightness(Objects::Visual::IColor::binary_color::turn_on);
				}
			}
		}
	}
}
