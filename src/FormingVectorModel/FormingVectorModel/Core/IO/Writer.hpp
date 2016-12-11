#ifndef FVM_CORE_IO_WRITER_HPP
#define FVM_CORE_IO_WRITER_HPP
#include <string>
#include "../Objects/Image/IImage.hpp"

namespace FVM
{
	namespace Core
	{
		namespace IO
		{
			class Writer
			{
			public:
				static void write(std::string path_to_file, Objects::Image::IImage *image);
			};
		}
	}
}
#endif
