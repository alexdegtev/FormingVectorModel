#ifndef FVM_CORE_OBJECTS_IMAGE_IIMAGE_HPP
#define FVM_CORE_OBJECTS_IMAGE_IIMAGE_HPP

#include "Pixel.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Image
			{
				class IImage
				{
				public:
					IImage() {}
					virtual ~IImage() {}

					virtual Pixel *pixel(int row, int col) = 0;
					virtual void pixel(int row, int col, Pixel *pixel) = 0;

					virtual int rows() = 0;
					virtual int cols() = 0;
				};
			}
		}
	}
}
#endif
