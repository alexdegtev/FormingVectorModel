#ifndef FVM_CORE_TRANSFORMATIONS_ISKELETIZATION_HPP
#define FVM_CORE_TRANSFORMATIONS_ISKELETIZATION_HPP

#include "ITransformation.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class ISkeletization : public ITransformation
			{
			public:
				virtual ~ISkeletization() {}
			};
		}
	}
}
#endif