#ifndef CORE_OBJECTS_VISUAL_IIMAGE_H
#define CORE_OBJECTS_VISUAL_IIMAGE_H

#include "IPixel.h"
#include <vector>
#include "../../Transformations/ITransformation.h"
#include "../../Vectorizations/IVectorization.h"

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
				virtual void transform(Transformations::ITransformation* transforamtion) = 0;
				virtual std::vector<Geometric::IObject*> vectorize(Vectorizations::IVectorization* vectorization) = 0;
			};
		}
	}
}

#endif
