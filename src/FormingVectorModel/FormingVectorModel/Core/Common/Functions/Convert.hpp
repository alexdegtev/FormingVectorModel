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
					static unsigned char RgbToBrightness(unsigned char red, unsigned char green, unsigned char blue);

					static void IImageToMat(Objects::Image::IImage *image, cv::Mat *mat);
					static void MatToIImage(cv::Mat *mat, Objects::Image::IImage *image);
				};
			}
		}
	}
}
#endif
