#ifndef CORE_VECTORIZATION_VECTORIZATION_H
#define CORE_VECTORIZATION_VECTORIZATION_H

#include "IVectorization.h"

// Version 2.0 of vectorization algorithm with intersection points.
// It's realization has disadvantages: right angles intersection convert to not right angles

namespace Core
{
	namespace Vectorization
	{
		class Vectorization : public IVectorization
		{
		public:
			std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) override;
		};
	}
}
#endif
