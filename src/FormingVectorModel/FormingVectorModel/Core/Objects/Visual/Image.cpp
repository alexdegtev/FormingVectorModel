#include "Image.h"

Core::Objects::Visual::Image::Image() : Image(0, 0)
{
}

Core::Objects::Visual::Image::Image(int rows, int cols) : _rows(rows), _cols(cols)
{
	_data = new Color[_rows * _cols];
}

Core::Objects::Visual::Image::~Image()
{
	if (_data)
		delete[] _data;
}

int Core::Objects::Visual::Image::rows()
{
	return _rows;
}

int Core::Objects::Visual::Image::cols()
{
	return _cols;
}

Core::Objects::Visual::IColor* Core::Objects::Visual::Image::get(int row, int col)
{
	if (row < _rows && col < _cols)
		return &_data[row * _cols + col];
	else
		throw "index out of range";
}

void Core::Objects::Visual::Image::set(int row, int col, IColor* value)
{
	if (row < _rows && col < _cols)
		_data[row * _cols + col] = Color(value->red(), value->green(), value->blue());
	else
		throw "index out of range";
}

void Core::Objects::Visual::Image::transform(Transformations::ITransformation* transforamtion)
{
	transforamtion->execute(this);
}

std::vector<Core::Objects::Geometric::IObject*> Core::Objects::Visual::Image::vectorize(Vectorizations::IVectorization* vectorization)
{
	return vectorization->execute(this);
}

std::vector<Core::Objects::Visual::IColor*> Core::Objects::Visual::Image::get_neighbours(int row, int col, unsigned char brightness)
{
	std::vector<IColor*> neighbours;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;

			int index = (row + i) * _cols + (col + j);
			if (0 <= row + i && row + i < _rows && 0 <= col + j && col + j < _cols &&
				_data[index].brightness() == brightness)
			{
				neighbours.push_back(&_data[index]);
			}
		}
	}

	return neighbours;
}

