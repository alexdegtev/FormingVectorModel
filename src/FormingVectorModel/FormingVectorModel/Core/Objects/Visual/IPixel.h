#ifndef CORE_OBJECTS_VISUAL_IPIXEL_H
#define CORE_OBJECTS_VISUAL_IPIXEL_H

#include "../Geometric/IPoint.h"
#include "IColor.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class IPixel : public Geometric::IPoint, public IColor
			{
			public:
				enum binary_state
				{
					turn_on = 0, // the pixels of interest (object)
					turn_off = 255 // background
				};

				virtual ~IPixel()
				{
				}
			};
		}
	}
}

#endif
