#ifndef FVM_CORE_COMMONFUNCTIONS_CONVERT_HPP
#define FVM_CORE_COMMONFUNCTIONS_CONVERT_HPP

namespace FVM
{
	namespace Core
	{
		namespace CommonFunctions
		{
			class Convert
			{
			public:
				static unsigned char rgb2brightness(unsigned char red, unsigned char green, unsigned char blue);
			};
		}
	}
}
#endif
