#ifndef CORE_TRANSFORMATION_INVERTATION_H
#define CORE_TRANSFORMATION_INVERTATION_H

#include "IInvertation.h"

namespace Core
{
	namespace Transformation
	{
		class Invertation : public IInvertation
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
