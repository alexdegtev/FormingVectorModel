#ifndef FVM_CORE_VECTORIZATION_IVECTORIZATION_HPP
#define FVM_CORE_VECTORIZATION_IVECTORIZATION_HPP

#include <vector>
#include "../Objects/Geometric/IObject.hpp"
#include "../Objects/Image/IImage.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Vectorization
		{
			class IVectorization
			{
			public:
				virtual ~IVectorization() {}

				virtual std::vector<Objects::Geometric::IObject*> vectorizate(Objects::Image::IImage *image) = 0;
			};
		}
	}
}
#endif
