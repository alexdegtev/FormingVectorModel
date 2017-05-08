#ifndef CORE_OBJECTS_VISUAL_IIMAGE_H
#define CORE_OBJECTS_VISUAL_IIMAGE_H

#include "IPixel.h"
#include <vector>
#include "../../Transformation/ITransformation.h"
#include "../../Vectorization/IVectorization.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class IImage
			{
			public:
				virtual ~IImage()
				{
				}

				virtual int rows() = 0;
				virtual int cols() = 0;
				virtual IColor* get(int row, int col) = 0;
				virtual void set(int row, int col, IColor* value) = 0;
				virtual void transform(Transformation::ITransformation* transforamtion) = 0;
				virtual std::vector<Geometric::IObject*> vectorize(Vectorization::IVectorization* vectorization) = 0;
				virtual std::vector<IColor*> get_neighbours(int row, int col, unsigned char brightness = IColor::binary_color::turn_on) = 0;
			};
		}
	}
}

#endif
