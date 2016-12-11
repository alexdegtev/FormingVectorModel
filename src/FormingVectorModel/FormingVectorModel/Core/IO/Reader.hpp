#ifndef FVM_CORE_IO_READER_HPP
#define FVM_CORE_IO_READER_HPP

#include <string>
#include "../Objects/Image/IImage.hpp"
#include "../Objects/Image/DefaultImage.hpp"

namespace FVM
{
	namespace Core
	{
		namespace IO
		{
			template <class T>
			class Reader
			{
			public:
				static Objects::Image::IImage *read(std::string path_to_file);
			};

			template class Reader<Objects::Image::DefaultImage>;
		}
	}
}
#endif
