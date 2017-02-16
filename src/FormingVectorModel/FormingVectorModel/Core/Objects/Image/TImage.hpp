#ifndef FVM_CORE_OBJECTS_IMAGE_IIMAGE_HPP
#define FVM_CORE_OBJECTS_IMAGE_IIMAGE_HPP

#include "Pixel.hpp"
#include "../../Transformations/ITransformation.hpp"
#include "../../Common/Types/Matrix.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Image
			{
				template<class _T>
				class TImage
				{
				public:
					TImage() : TImage(0, 0) {}
					TImage(int rows, int cols)
					{
						_data = new Common::Types::Matrix<_T>(rows, cols);
					}
					TImage(const TImage& other) {}
					TImage(const TImage* other) {}
					~TImage()
					{
						delete _data;
					}

					_T* pixel(int row, int col)
					{
						return (*_data)(row, col);
					}

					void pixel(int row, int col, _T* pixel)
					{
						*_data->operator()(row, col) = pixel;
					}

					int rows()
					{
						return _data->rows();
					}

					int cols()
					{
						return _data->cols();
					}

					void transform(Transformations::ITransformation* transformation)
					{
					}

					TImage* copy()
					{
						
					}

				private:
					Common::Types::Matrix<_T>* _data;
				};
			}
		}
	}
}
#endif
