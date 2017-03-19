﻿#include "ImageWithVisitedMarks.h"
#include "../Objects/Geometric/Point.h"

Core::Vectorizations::ImageWithVisitedMarks::ImageWithVisitedMarks() : ImageWithVisitedMarks(nullptr)
{
}

Core::Vectorizations::ImageWithVisitedMarks::ImageWithVisitedMarks(Objects::Visual::IImage* image) : _rows(image->rows()), _cols(image->cols())
{
	_data = new Pixel[_rows * _cols];

	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _cols; j++)
		{
			_data[i * _cols + j] = { image->get(i, j), new Objects::Geometric::Point(i, j), VisitState::unvisited };
		}
	}
}

Core::Vectorizations::ImageWithVisitedMarks::~ImageWithVisitedMarks()
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		delete _data[i].point;
	}

	if (_data)
		delete[] _data;
}

int Core::Vectorizations::ImageWithVisitedMarks::rows() const
{
	return _rows;
}

int Core::Vectorizations::ImageWithVisitedMarks::cols() const
{
	return _cols;
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::get(int row, int col) const
{
	if (row < _rows && col < _cols)
		return &_data[row * _cols + col];
	else
		throw "index out of range";
}

void Core::Vectorizations::ImageWithVisitedMarks::set(int row, int col, Pixel* value)
{
	if (row < _rows && col < _cols)
		_data[row * _cols + col] = { value->color, value->point, value->state };
	else
		throw "index out of range";
}

void Core::Vectorizations::ImageWithVisitedMarks::convert_all_excluded_to_unvisited()
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		if (_data[i].state == VisitState::excluded)
		{
			_data[i].state = VisitState::unvisited;
		}
	}
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::get_first_unvisited()
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		if (_data[i].state == VisitState::unvisited)
		{
			if (_data[i].color->brightness() == Objects::Visual::IColor::binary_color::turn_on)
			{
				return &_data[i];
			}
			else
			{
				_data[i].state = VisitState::visited;
			}
		}
	}

	return nullptr;
}

std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::ImageWithVisitedMarks::get_neighbours(Pixel* central)
{
	int row = central->point->x();
	int col = central->point->y();

	std::vector<Pixel*> neighbours;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;

			int index = (row + i) * _cols + (col + j);
			if (0 <= row + i && row + i < _rows && 0 <= col + j && col + j < _cols &&
				_data[index].color->brightness() == Objects::Visual::IColor::binary_color::turn_on &&
				_data[index].state != VisitState::excluded)
			{
				neighbours.push_back(&_data[index]);
			}
		}
	}

	return neighbours;
}

std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::ImageWithVisitedMarks::get_neighbours_with_excluded(Pixel* central)
{
	int row = central->point->x();
	int col = central->point->y();

	std::vector<Pixel*> neighbours;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;

			int index = (row + i) * _cols + (col + j);
			if (0 <= row + i && row + i < _rows && 0 <= col + j && col + j < _cols &&
				_data[index].color->brightness() == Objects::Visual::IColor::binary_color::turn_on)
			{
				neighbours.push_back(&_data[index]);
			}
		}
	}

	return neighbours;
}

bool Core::Vectorizations::ImageWithVisitedMarks::has_unvisited_pixels() const
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		if (_data[i].state == VisitState::unvisited)
		{
			return true;
		}
	}

	return false;
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::vertical_or_horizontal_neighbour(Pixel* central, std::vector<Pixel*> neighbours)
{
	Objects::Geometric::IPoint* c = central->point;
	for (auto neighbour : neighbours)
	{
		Objects::Geometric::IPoint *n = neighbour->point;
		if (c->x() + 1 == n->x() && c->y() == n->y() ||
			c->x() - 1 == n->x() && c->y() == n->y() ||
			c->x() == n->x() && c->y() + 1 == n->y() ||
			c->x() == n->x() && c->y() - 1 == n->y())
		{
			return neighbour;
		}
	}

	return nullptr;
}

bool Core::Vectorizations::ImageWithVisitedMarks::is_aligned(Pixel* a, Pixel* b, Pixel* c)
{
	Objects::Geometric::IPoint *p_a = a->point;
	Objects::Geometric::IPoint *p_b = b->point;
	Objects::Geometric::IPoint *p_c = c->point;
	return (p_a->x() - p_c->x()) * (p_b->y() - p_c->y()) == (p_b->x() - p_c->x()) * (p_a->y() - p_c->y());
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::find_aligned(Pixel* previous, Pixel* central, std::vector<Pixel*> neighbours)
{
	for(auto n : neighbours)
	{
		if(is_aligned(previous, central, n))
		{
			return n;
		}
	}

	return nullptr;
}
