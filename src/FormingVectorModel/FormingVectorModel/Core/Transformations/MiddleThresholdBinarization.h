#ifndef CORE_TRANSFORMATIONS_MIDDLETHRESHOLDBINARIZATION_H
#define CORE_TRANSFORMATIONS_MIDDLETHRESHOLDBINARIZATION_H

#include "IBinarization.h"

namespace Core
{
	namespace Transformations
	{
		class MiddleThresholdBinarization : public IBinarization
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
