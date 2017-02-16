#ifndef FVM_CORE_OBJECTS_IMAGE_IPIXEL_HPP
#define FVM_CORE_OBJECTS_IMAGE_IPIXEL_HPP

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Image
			{
				class IPixel
				{
				public:
					virtual ~IPixel(){}

					virtual unsigned char red() = 0;
					virtual void red(unsigned char value) = 0;

					virtual unsigned char green() = 0;
					virtual void green(unsigned char value) = 0;

					virtual unsigned char blue() = 0;
					virtual void blue(unsigned char value) = 0;

					virtual unsigned char brightness() = 0;
					virtual void brightness(unsigned char value) = 0;
				};
			}
		}
	}
}
#endif