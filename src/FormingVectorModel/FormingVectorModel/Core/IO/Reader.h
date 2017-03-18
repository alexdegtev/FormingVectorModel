#ifndef CORE_IO_READER_H
#define CORE_IO_READER_H

#include "../Objects/Visual/IImage.h"
#include "Path.h"

namespace Core
{
	namespace IO
	{
		class Reader
		{
		public:
			static Objects::Visual::IImage* read(std::string path);
			static Objects::Visual::IImage* read(Path path);
		};
	}
}

#endif
