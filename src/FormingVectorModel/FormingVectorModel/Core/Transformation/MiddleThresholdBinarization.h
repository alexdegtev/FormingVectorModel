#ifndef CORE_TRANSFORMATION_MIDDLETHRESHOLDBINARIZATION_H
#define CORE_TRANSFORMATION_MIDDLETHRESHOLDBINARIZATION_H

#include "IBinarization.h"

namespace Core
{
	namespace Transformation
	{
		class MiddleThresholdBinarization : public IBinarization
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
