#ifndef CORE_OBJECTS_VISUAL_COLOR_H
#define CORE_OBJECTS_VISUAL_COLOR_H

#include "IColor.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class Color : public IColor
			{
			public:
				Color();
				Color(unsigned char brightness);
				Color(IColor* c);
				Color(unsigned char red, unsigned char green, unsigned char blue);

				unsigned char red() const override;
				void red(unsigned char value) override;

				unsigned char green() const override;
				void green(unsigned char value) override;

				unsigned char blue() const override;
				void blue(unsigned char value) override;

				unsigned char brightness() const override;
				void brightness(unsigned char value) override;

			private:
				unsigned char _red;
				unsigned char _green;
				unsigned char _blue;
			};
		}
	}
}

#endif
