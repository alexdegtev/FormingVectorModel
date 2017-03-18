#ifndef CORE_IO_WRITER_H
#define CORE_IO_WRITER_H

#include <string>
#include "../Objects/Visual/IImage.h"
#include "Path.h"

namespace Core
{
	namespace IO
	{
		class Writer
		{
		public:
			static void write(std::string path, Objects::Visual::IImage* image);
			static void write(Path path, Objects::Visual::IImage* image);
		};
	}
}

#endif
