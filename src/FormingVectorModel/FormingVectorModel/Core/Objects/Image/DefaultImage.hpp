#ifndef FVM_CORE_OBJECTS_IMAGE_DEFAULTIMAGE_HPP
#define FVM_CORE_OBJECTS_IMAGE_DEFAULTIMAGE_HPP

#include "IImage.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Image
			{
				class DefaultImage : public IImage
				{
				public:
					DefaultImage();
					DefaultImage(int rows, int cols);
					~DefaultImage();

					Pixel *pixel(int row, int col) override;
					void pixel(int row, int col, Pixel *pixel) override;

					int rows() override;
					int cols() override;

					void transform(Transformations::ITransformation* transformation) override;

				private:
					Pixel *data;
					int rows_;
					int cols_;
				};
			}
		}
	}
}
#endif
