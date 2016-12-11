#ifndef FVM_CORE_TRANSFORMATIONS_YIQGRAYSCALE_HPP
#define FVM_CORE_TRANSFORMATIONS_YIQGRAYSCALE_HPP

#include "IGrayscale.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class YIQGrayscale : public IGrayscale
			{
			public:
				void execute(Objects::Image::IImage* image) override;
			};
		}
	}
}
#endif
