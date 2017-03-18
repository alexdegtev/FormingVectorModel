#ifndef CORE_OBJECTS_VISUAL_ICOLOR_H
#define CORE_OBJECTS_VISUAL_ICOLOR_H

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class IColor
			{
			public:
				enum binary_color
				{
					turn_on = 255, // the pixels of interest (object)
					turn_off = 0 // background
				};

				virtual ~IColor()
				{
				}

				virtual unsigned char red() const = 0;
				virtual void red(unsigned char value) = 0;

				virtual unsigned char green() const = 0;
				virtual void green(unsigned char value) = 0;

				virtual unsigned char blue() const = 0;
				virtual void blue(unsigned char value) = 0;

				virtual unsigned char brightness() const = 0;
				virtual void brightness(unsigned char value) = 0;
			};
		}
	}
}

#endif
