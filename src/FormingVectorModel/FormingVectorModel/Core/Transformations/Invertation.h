#ifndef CORE_TRANSFORMATIONS_INVERTATION_H
#define CORE_TRANSFORMATIONS_INVERTATION_H

#include "IInvertation.h"

namespace Core
{
	namespace Transformations
	{
		class Invertation : public IInvertation
		{
		public:
			void execute(Objects::Visual::IImage* image) override;
		};
	}
}

#endif
