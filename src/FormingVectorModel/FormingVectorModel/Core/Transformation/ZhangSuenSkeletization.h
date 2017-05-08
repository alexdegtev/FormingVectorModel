/**
* Code for thinning a binary image using Zhang-Suen algorithm.
* http://opencv-code.com/quick-tips/implementation-of-thinning-algorithm-in-opencv/
*/
#ifndef CORE_TRANSFORMATION_ZHANGSUENSKELETIZATION_H
#define CORE_TRANSFORMATION_ZHANGSUENSKELETIZATION_H

#include "ISkeletization.h"
#include "opencv2/opencv.hpp"

namespace Core
{
	namespace Transformation
	{
		class ZhangSuenSkeletization : public ISkeletization
		{
		public:
			void execute(Objects::Visual::IImage* image) override;

		private:
			void thinning(cv::Mat& im);
			void thinning_iteration(cv::Mat& im, int iter);
		};
	}
}

#endif
