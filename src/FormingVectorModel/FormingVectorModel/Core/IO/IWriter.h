#ifndef CORE_IO_IWRITER_H
#define CORE_IO_IWRITER_H

#include <string>
#include "../Objects/Visual/IImage.h"
#include "IPath.h"

namespace Core
{
	namespace IO
	{
		class IWriter
		{
		public:
			virtual ~IWriter() { }

			virtual void write(std::string path, Objects::Visual::IImage *image) = 0;
			virtual void write(IPath *path, Objects::Visual::IImage *image) = 0;
		};
	}
}

#endif
