#ifndef FVM_CORE_TRANSFORMATIONS_IGRAYSCALE_HPP
#define FVM_CORE_TRANSFORMATIONS_IGRAYSCALE_HPP

#include "ITransformation.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class IGrayscale : public ITransformation
			{
			public:
				virtual ~IGrayscale() {}
			};
		}
	}
}
#endif
