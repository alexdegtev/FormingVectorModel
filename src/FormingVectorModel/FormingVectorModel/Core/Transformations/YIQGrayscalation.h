#ifndef CORE_TRANSFORMATIONS_YIQGRAYSCALATION_H
#define CORE_TRANSFORMATIONS_YIQGRAYSCALATION_H

#include "IGrayscalation.h"

namespace Core
{
	namespace Transformations
	{
		class YIQGrayscalation : public IGrayscalation
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
