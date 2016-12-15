#ifndef FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION_HPP
#define FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION_HPP

#include "IVectorization.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Vectorization
		{
			class DefaultVectorization : public IVectorization
			{
			public:
				std::vector<Objects::Geometric::IObject> vectorizate(Objects::Image::IImage* image) override;
			};
		}
	}
}
#endif
