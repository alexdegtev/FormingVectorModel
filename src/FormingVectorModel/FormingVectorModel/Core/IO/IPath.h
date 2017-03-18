#ifndef CORE_IO_IPATH_H
#define CORE_IO_IPATH_H

#include <string>

namespace Core
{
	namespace IO
	{
		class IPath
		{
		public:
			virtual ~IPath() { }

			virtual std::string path_to_file() = 0;
			virtual std::string file_name() = 0;
			virtual std::string file_extention() = 0;
			virtual std::string full_path() = 0;
		};		
	}
}

#endif
