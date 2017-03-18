#ifndef CORE_IO_PATH_H
#define CORE_IO_PATH_H

#include <string>

namespace Core
{
	namespace IO
	{
		class Path
		{
		public:
			Path(std::string full_path);
			Path(std::string path_to_file, std::string file_name, std::string file_extention);

			std::string path_to_file() const;
			std::string file_name() const;
			std::string file_extention() const;
			std::string full_path() const;

		private:
			std::string _path_to_file;
			std::string _file_name;
			std::string _file_extention;

#ifdef _WIN32
			char _separator = '\\';
#elif _unix_
			char _separator = '/';
#endif
		};
	}
}

#endif
