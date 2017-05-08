#include "ImageWithVisitedMarks.h"
#include "../Objects/Geometric/Point.h"

Core::Vectorization::ImageWithVisitedMarks::ImageWithVisitedMarks() : ImageWithVisitedMarks(nullptr)
{
}

Core::Vectorization::ImageWithVisitedMarks::ImageWithVisitedMarks(Objects::Visual::IImage* image) : _rows(image->rows()), _cols(image->cols())
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

Core::Vectorization::ImageWithVisitedMarks::~ImageWithVisitedMarks()
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		delete _data[i].point;
	}

	if (_data)
		delete[] _data;
}

int Core::Vectorization::ImageWithVisitedMarks::rows() const
{
	return _rows;
}

int Core::Vectorization::ImageWithVisitedMarks::cols() const
{
	return _cols;
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::ImageWithVisitedMarks::get(int row, int col) const
{
	if (row < _rows && col < _cols)
		return &_data[row * _cols + col];
	else
		throw "index out of range";
}

void Core::Vectorization::ImageWithVisitedMarks::set(int row, int col, Pixel* value)
{
	if (row < _rows && col < _cols)
		_data[row * _cols + col] = { value->color, value->point, value->state };
	else
		throw "index out of range";
}

void Core::Vectorization::ImageWithVisitedMarks::convert_all_excluded_to_unvisited()
{
	for (int i = 0; i < _rows * _cols; i++)
	{
		if (_data[i].state == VisitState::excluded)
		{
			_data[i].state = VisitState::unvisited;
		}
	}
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::ImageWithVisitedMarks::get_first_unvisited()
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

std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> Core::Vectorization::ImageWithVisitedMarks::get_neighbours(Pixel* central)
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

std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> Core::Vectorization::ImageWithVisitedMarks::get_neighbours_with_excluded(Pixel* central)
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

bool Core::Vectorization::ImageWithVisitedMarks::has_unvisited_pixels() const
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

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::ImageWithVisitedMarks::vertical_or_horizontal_neighbour(Pixel* central, std::vector<Pixel*> neighbours)
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

bool Core::Vectorization::ImageWithVisitedMarks::is_aligned(Pixel* a, Pixel* b, Pixel* c)
{
	Objects::Geometric::IPoint *p_a = a->point;
	Objects::Geometric::IPoint *p_b = b->point;
	Objects::Geometric::IPoint *p_c = c->point;
	return (p_a->x() - p_c->x()) * (p_b->y() - p_c->y()) == (p_b->x() - p_c->x()) * (p_a->y() - p_c->y());
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::ImageWithVisitedMarks::find_aligned(Pixel* previous, Pixel* central, std::vector<Pixel*> neighbours)
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

std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> Core::Vectorization::ImageWithVisitedMarks::get_horizontal_neigbour(Pixel* previous, Pixel* center)
{
	std::vector<Pixel*> result;

	for(auto n:get_neighbours(center))
	{
		if(is_horizontal_neighbour(previous, center, n))
		{
			result.push_back(n);
		}
	}

	return result;
}

bool Core::Vectorization::ImageWithVisitedMarks::is_horizontal_neighbour(Pixel* previous, Pixel* center, Pixel* neighbour)
{
	// L-shaped angle
	if (previous->point->x() == center->point->x() && previous->point->y() != center->point->y() ||
		previous->point->x() != center->point->x() && previous->point->y() == center->point->y())
	{
		int a = previous->point->x() - neighbour->point->x();
		int b = previous->point->y() - neighbour->point->y();
		return (a * a + b * b) == 2;
	}
	
	// V-shaped angle
	if (previous->point->x() == neighbour->point->x() && previous->point->y() != neighbour->point->y() ||
		previous->point->x() != neighbour->point->x() && previous->point->y() == neighbour->point->y())
	{
		int a = previous->point->x() - neighbour->point->x();
		int b = previous->point->y() - neighbour->point->y();
		return (a * a + b * b) == 4;
	}

	return false;
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::ImageWithVisitedMarks::get_horizontal_or_vertical_neighbour(Pixel* center, std::vector<Pixel*> neighbours)
{
	for (auto n : neighbours) {
		if (center->point->x() + 1 == n->point->x() && center->point->y() == n->point->y() ||
			center->point->x() - 1 == n->point->x() && center->point->y() == n->point->y() ||
			center->point->x() == n->point->x() && center->point->y() + 1 == n->point->y() ||
			center->point->x() == n->point->x() && center->point->y() - 1 == n->point->y())
		{
			return n;
		}
	}
	return nullptr;
}
