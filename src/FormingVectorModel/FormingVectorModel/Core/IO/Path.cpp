#include "Path.h"

Core::IO::Path::Path(std::string full_path)
{
	int position;
	for (position = full_path.size() - 1; full_path[position] != '.'; position--)
	{
		_file_extention += full_path[position];
	}
	std::reverse(_file_extention.begin(), _file_extention.end());

	if (_file_extention.empty())
	{
		position = full_path.size() - 1;
	}
	else
	{
		position--;
	}

	for (; full_path[position] != '/' && full_path[position] != '\\'; position--)
	{
		_file_name += full_path[position];
	}
	std::reverse(_file_name.begin(), _file_name.end());

	position--;

	for (; position >= 0; position--)
	{
		_path_to_file += full_path[position];
	}
	std::reverse(_path_to_file.begin(), _path_to_file.end());
}

Core::IO::Path::Path(std::string path_to_file, std::string file_name, std::string file_extention) : _path_to_file(path_to_file), _file_name(file_name), _file_extention(file_extention)
{
}

std::string Core::IO::Path::path_to_file() const
{
	return _path_to_file;
}

std::string Core::IO::Path::file_name() const
{
	return _file_name;
}

std::string Core::IO::Path::file_extention() const
{
	return _file_extention;
}

std::string Core::IO::Path::full_path() const
{
	return _path_to_file + _separator + _file_name + '.' + _file_extention;
}
