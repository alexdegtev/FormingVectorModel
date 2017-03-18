#ifndef CORE_OBJECTS_VISUAL_PIXEL_H
#define CORE_OBJECTS_VISUAL_PIXEL_H

#include "IPixel.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class Pixel : public IPixel
			{
			public:
				Pixel();
				Pixel(IPoint* point, IColor* color);
				Pixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue);
				Pixel(unsigned char red, unsigned char green, unsigned char blue);
				Pixel(int x, int y, unsigned char brightness);
				Pixel(IPixel* other);
				~Pixel();

				int x() const override;
				int y() const override;

				unsigned char red() const override;
				void red(unsigned char value) override;

				unsigned char green() const override;
				void green(unsigned char value) override;

				unsigned char blue() const override;
				void blue(unsigned char value) override;

				unsigned char brightness() const override;
				void brightness(unsigned char value) override;

			private:
				IPoint* _point;
				IColor* _color;
			};
		}
	}
}

#endif
