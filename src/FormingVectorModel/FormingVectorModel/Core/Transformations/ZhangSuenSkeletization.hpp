/**
* Code for thinning a binary image using Zhang-Suen algorithm.
* http://opencv-code.com/quick-tips/implementation-of-thinning-algorithm-in-opencv/
*/
#ifndef FVM_CORE_TRANSFORMATIONS_ZHANGSUENSKELETIZATION_HPP
#define FVM_CORE_TRANSFORMATIONS_ZHANGSUENSKELETIZATION_HPP

#include "ISkeletization.hpp"
#include <opencv2/core/mat.hpp>

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class ZhangSuenSkeletization : public ISkeletization
			{
			public:
				void execute(Objects::Image::IImage* image) override;

			private:
				/**
				* Function for thinning the given binary image
				*
				* @param  im  Binary image with range = 0-255
				*/
				void thinning(cv::Mat& im);

				/**
				* Perform one thinning iteration.
				* Normally you wouldn't call this function directly from your code.
				*
				* @param  im    Binary image with range = 0-1
				* @param  iter  0=even, 1=odd
				*/
				void thinning_iteration(cv::Mat& im, int iter);
			};
		}
	}
}
#endif