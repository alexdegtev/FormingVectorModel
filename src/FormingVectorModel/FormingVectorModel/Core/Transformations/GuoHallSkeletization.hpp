/**
* Code for thinning a binary image using Guo-Hall algorithm.
* http://opencv-code.com/quick-tips/implementation-of-guo-hall-thinning-algorithm/
*/
#ifndef FVM_CORE_TRANSFORMATIONS_GUOHALLSKELETIZATION_HPP
#define FVM_CORE_TRANSFORMATIONS_GUOHALLSKELETIZATION_HPP

#include "ISkeletization.hpp"
#include <opencv2/core/mat.hpp>

namespace FVM
{
	namespace Core
	{
		namespace Transformations
		{
			class GuoHallSkeletization : public ISkeletization
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