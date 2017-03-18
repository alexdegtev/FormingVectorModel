#ifndef CORE_IO_IREADER_H
#define CORE_IO_IREADER_H

#include "../Objects/Visual/IImage.h"
#include <string>
#include "IPath.h"

namespace Core
{
	namespace IO
	{
		class IReader
		{
		public:
			virtual ~IReader() { }

			virtual Objects::Visual::IImage *read(std::string path) = 0;
			virtual Objects::Visual::IImage *read(IPath *path) = 0;
		};
	}
}

#endif
