#ifndef CORE_VECTORIZATIONS_VECTORIZATION_H
#define CORE_VECTORIZATIONS_VECTORIZATION_H

#include "IVectorization.h"

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
