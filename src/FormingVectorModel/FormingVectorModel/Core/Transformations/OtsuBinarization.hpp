#ifndef FVM_CORE_TRANSFORMATIONS_OTSUBINARIZATION_HPP
#define FVM_CORE_TRANSFORMATIONS_OTSUBINARIZATION_HPP

#include "IBinarization.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class OtsuBinarization : public IBinarization
			{
			public:
				void execute(Objects::Image::IImage *image) override;

			private:
				unsigned char turn_on_pixel = 255;	// the pixels of interest (object)
				unsigned char turn_off_pixel = 0;	// background

				unsigned char threshold(Objects::Image::IImage *image);
			};
		}
	}
}
#endif