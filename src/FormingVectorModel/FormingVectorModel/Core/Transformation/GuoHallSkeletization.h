/**
* Code for thinning a binary image using Guo-Hall algorithm.
* http://opencv-code.com/quick-tips/implementation-of-guo-hall-thinning-algorithm/
*/
#ifndef CORE_TRANSFORMATION_GUOHALLSKELETIZATION_H
#define CORE_TRANSFORMATION_GUOHALLSKELETIZATION_H

#include "ISkeletization.h"
#include "opencv2/opencv.hpp"

namespace Core
{
	namespace Transformation
	{
		class GuoHallSkeletization : public ISkeletization
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
