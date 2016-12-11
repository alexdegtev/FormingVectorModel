#ifndef FVM_CORE_OBJECTS_IMAGE_PIXEL_HPP
#define FVM_CORE_OBJECTS_IMAGE_PIXEL_HPP

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

					Pixel operator=(const Pixel& other) const;

					unsigned char red() const;
					void red(unsigned char value);

					unsigned char green() const;
					void green(unsigned char value);

					unsigned char blue() const;
					void blue(unsigned char value);

					unsigned char brightness() const;
					void brightness(unsigned char value);

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