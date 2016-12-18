#ifndef FVM_CORE_COMMON_FUNCTIONS_CONVERT_HPP
#define FVM_CORE_COMMON_FUNCTIONS_CONVERT_HPP

#include "../../Objects/Image/IImage.hpp"
#include <opencv2/core/mat.hpp>

namespace FVM
{
	namespace Core
	{
		namespace Common
		{
			namespace Functions {
				class Convert
				{
				public:
					static unsigned char rgb2brightness(unsigned char red, unsigned char green, unsigned char blue);

					static void iimage2mat(Objects::Image::IImage *image, cv::Mat *mat);
					static void mat2iimage(cv::Mat *mat, Objects::Image::IImage *image);
				};
			}
		}
	}
}
#endif
