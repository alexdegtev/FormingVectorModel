#ifndef CORE_VECTORIZATIONS_VECTORIZATION_H
#define CORE_VECTORIZATIONS_VECTORIZATION_H

#include "IVectorization.h"

// Version 1.0 of vectorization algorithm.
// It's realization has disadvantages: right angles intersection convert to not right angles

namespace Core
{
	namespace Vectorizations
	{
		class Vectorization : public IVectorization
		{
		public:
			std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) override;
		};
	}
}
#endif
