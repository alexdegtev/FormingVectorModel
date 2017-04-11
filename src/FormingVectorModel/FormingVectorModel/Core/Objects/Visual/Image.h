#ifndef CORE_OBJECTS_VISUAL_IMAGE_H
#define CORE_OBJECTS_VISUAL_IMAGE_H

#include "IImage.h"
#include "Color.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class Image : public IImage
			{
			public:
				Image();
				Image(int rows, int cols);
				~Image();

				int rows() override;
				int cols() override;
				IColor* get(int row, int col) override;
				void set(int row, int col, IColor* value) override;
				void transform(Transformations::ITransformation* transforamtion) override;
				std::vector<Geometric::IObject*> vectorize(Vectorizations::IVectorization* vectorization) override;
				std::vector<IColor*> get_neighbours(int row, int col, unsigned char brightness = IColor::binary_color::turn_on) override;
			private:
				Color* _data;
				int _rows;
				int _cols;
			};
		}
	}
}

#endif
