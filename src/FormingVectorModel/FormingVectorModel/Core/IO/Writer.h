#ifndef CORE_IO_WRITER_H
#define CORE_IO_WRITER_H

#include <string>
#include "../Objects/Visual/IImage.h"
#include "Path.h"
#include "../Objects/Visual/Drawing.h"

namespace Core
{
	namespace IO
	{
		class Writer
		{
		public:
			static void write(Path path, Objects::Visual::IImage* image);
			static void write(Path path, std::vector<Objects::Geometric::IObject*> objects, Objects::Visual::IImage* image);

		private:
			static void write_raster(std::string path, Objects::Visual::IImage* image);
			static void write_svg(std::string path, std::vector<Objects::Geometric::IObject*> objects, Objects::Visual::IImage* image);
			static void write_xml(std::string path, std::vector<Objects::Geometric::IObject*> objects);
			static void write_xml(std::string path, Objects::Visual::Drawing* drawing);
		};
	}
}

#endif
