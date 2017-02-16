#ifndef FVM_CORE_OBJECTS_IMAGE_PIXEL_HPP
#define FVM_CORE_OBJECTS_IMAGE_PIXEL_HPP

#include <ostream>
#include "IPixel.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Image
			{
				class Pixel : public IPixel
				{
				public:
					Pixel();
					Pixel(unsigned char brightness);
					Pixel(unsigned char red, unsigned char green, unsigned char blue);
					Pixel(const Pixel& other);

					unsigned char red() override;
					void red(unsigned char value) override;

					unsigned char green() override;
					void green(unsigned char value) override;

					unsigned char blue() override;
					void blue(unsigned char value) override;

					unsigned char brightness() override;
					void brightness(unsigned char value) override;

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