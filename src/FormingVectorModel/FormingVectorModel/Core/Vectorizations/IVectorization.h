#ifndef CORE_VECTORIZATIONS_IVECTORIZATION_H
#define CORE_VECTORIZATIONS_IVECTORIZATION_H

#include <vector>
#include "../Objects/Geometric/IObject.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class IImage;
		}
	}
}

namespace Core
{
	namespace Vectorizations
	{
		class IVectorization
		{
		public:
			virtual ~IVectorization()
			{
			}

			virtual std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) = 0;
		};
	}
}

#endif
