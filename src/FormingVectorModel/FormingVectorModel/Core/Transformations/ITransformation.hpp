#ifndef FVM_CORE_TRANSFORMATIONS_ITRANSFORMATION_HPP
#define FVM_CORE_TRANSFORMATIONS_ITRANSFORMATION_HPP

#include "../Objects/Image/IImage.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class ITransformation
			{
			public:
				virtual ~ITransformation() {}
				virtual void execute(Objects::Image::IImage *image) = 0;
			};
		}
	}
}
#endif
