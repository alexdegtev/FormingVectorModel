#ifndef CORE_COMMON_FUNCTIONS
#define CORE_COMMON_FUNCTIONS

#include "../Objects/Visual/IImage.h"
#include "opencv2/opencv.hpp"

namespace Core
{
	namespace Common
	{
		class Functions
		{
		public:
			static unsigned char rgb_to_brightness(unsigned char red, unsigned char green, unsigned char blue);
			static void iimage_to_mat(Objects::Visual::IImage* image, cv::Mat* mat);
			static void mat_to_iimage(cv::Mat* mat, Objects::Visual::IImage* image);
			static bool is_aligned(Objects::Geometric::IPoint* a, Objects::Geometric::IPoint* b, Objects::Geometric::IPoint* c);
			static Objects::Geometric::IPoint* vertical_or_horizontal_neighbour(Objects::Geometric::IPoint* central_point, std::vector<Core::Objects::Geometric::IPoint*> neighbours);
		};
	}
}

#endif
