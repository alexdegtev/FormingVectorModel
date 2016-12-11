#ifndef FVM_CORE_OBJECTS_IMAGE_PIXEL_HPP
#define FVM_CORE_OBJECTS_IMAGE_PIXEL_HPP

#include <ostream>

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Image
			{
				class Pixel
				{
				public:
					Pixel();
					Pixel(unsigned char brightness);
					Pixel(unsigned char red, unsigned char green, unsigned char blue);
					Pixel(const Pixel& other);

					unsigned char red() const;
					void red(unsigned char value);

					unsigned char green() const;
					void green(unsigned char value);

					unsigned char blue() const;
					void blue(unsigned char value);

					unsigned char brightness() const;
					void brightness(unsigned char value);

					Pixel operator= (const Pixel& other);
					friend std::ostream& operator<< (std::ostream& os, const Pixel& dt);

				private:
					unsigned char red_;
					unsigned char green_;
					unsigned char blue_;
				};
			}
		}
	}
}
#endif