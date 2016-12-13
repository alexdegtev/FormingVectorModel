#ifndef FVM_CORE_TRANSFORMATIONS_IBINARIZATION_HPP
#define FVM_CORE_TRANSFORMATIONS_IBINARIZATION_HPP

#include "ITransformation.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class IBinarization : public ITransformation
			{
			public:
				virtual ~IBinarization() {}
			};
		}
	}
}
#endif
