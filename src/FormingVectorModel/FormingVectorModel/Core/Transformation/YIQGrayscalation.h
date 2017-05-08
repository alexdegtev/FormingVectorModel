#ifndef CORE_TRANSFORMATION_YIQGRAYSCALATION_H
#define CORE_TRANSFORMATION_YIQGRAYSCALATION_H

#include "IGrayscalation.h"

namespace Core
{
	namespace Transformation
	{
		class YIQGrayscalation : public IGrayscalation
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
