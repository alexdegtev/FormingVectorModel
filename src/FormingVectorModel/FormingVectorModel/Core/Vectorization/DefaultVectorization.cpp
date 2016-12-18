#include "DefaultVectorization.hpp"
#include "../Objects/Geometric/Line.hpp"

std::vector<IObject*> FVM::Core::Vectorization::DefaultVectorization::vectorizate(Objects::Image::IImage* image)
{
	// Скопируем изображение
	_image = image->copy();

	std::vector<Objects::Geometric::IObject*> lines;

	// Создаём массив меток посещённости пикселей
	_vizit_matrix = new VizitMatrix(_image->rows(), _image->cols());
	Point *prev = nullptr, *cur = nullptr, *start = nullptr;

	while (!_vizit_matrix->is_all_visit())
	{
		// Находим первый нефоновый не посещённый пиксель
		if(!cur)
		{
			cur = find_first_not_visited();
			if(!cur)
				break;
		}


		std::vector<Point*> neighbours = find_neighbours(cur->x(), cur->y());

		switch (neighbours.size())
		{
		case 1:
			_vizit_matrix->visit(cur->x(), cur->y());
			
			if(!start)
			{
				prev = start = cur;
				cur = neighbours[0];
			}
			else
			{
				lines.push_back(new Line(*start, *cur));
				delete start;
				start = prev = cur = nullptr;
			}
			break;

		case 2:
			_vizit_matrix->visit(cur->x(), cur->y());

			if (!start) // Начинаем движение
			{
				prev = start = cur;
				cur = neighbours[0];
			}
			else // Движемся по прямой
			{
				//TODO: Если обе уже посещены
				if(_vizit_matrix->is_visit(neighbours[0]->x(), neighbours[0]->y()) && _vizit_matrix->is_visit(neighbours[1]->x(), neighbours[1]->y()))
				{
					throw "Обе соседние вершины уже посещены";
				}

				// Выбираем следующую непосещённую
				Point *next = _vizit_matrix->is_visit(neighbours[0]->x(), neighbours[0]->y()) ? neighbours[1] : neighbours[0];

				// Находятся ли предыдущая, текущая и соседняя точки на одной прямой
				if (is_on_straight_line(*prev, *cur, *next)) // Продолжаем двигаться по прямой
				{
					prev = cur;
				}
				else // Находимся на точке соприкосновения двух отрезков
				{
					lines.push_back(new Line(*start, *cur));
					start = prev = cur;
				}
				cur = next;
			}
			break;

		default:
			break;
		}
	}
		

	delete _vizit_matrix;
	delete _image;
	return lines;
}

std::vector<Point*> FVM::Core::Vectorization::DefaultVectorization::find_neighbours(int row, int col)
{
	std::vector<Point*> neighbours;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0) continue;

			Pixel *p = _image->pixel(row + i, col + j);
			if (p && p->brightness() == 255)
				neighbours.push_back(new Point(row + i, col + j));
		}
	}

	return neighbours;
}

bool FVM::Core::Vectorization::DefaultVectorization::is_on_straight_line(Point a, Point b, Point c) const
{
	return (a.x() - c.x()) * (b.y() - c.y()) == (b.x() - c.x()) * (a.y() - c.y());
}

Point* FVM::Core::Vectorization::DefaultVectorization::find_first_not_visited()
{
	int i = 0, j = 0;
	bool is_find = false;
	for (i = 0; i < _image->rows(); i++)
	{
		for (j = 0; j < _image->cols(); j++)
		{
			if (_image->pixel(i, j)->brightness() == 255 && !_vizit_matrix->is_visit(i, j))
			{
				is_find = true;
				break;
			}
			else
			{
				_vizit_matrix->visit(i, j);
			}
		}

		if (is_find)
			break;
	}

	return is_find ? new Point(i, j) : nullptr;
}

FVM::Core::Vectorization::VizitMatrix::VizitMatrix(int rows, int cols) : _rows(rows), _cols(cols), _count(rows * cols)
{
	_data = new bool[_rows * _cols];
	for (int i = 0; i < _rows * _cols; i++)
		_data[i] = false;
}

FVM::Core::Vectorization::VizitMatrix::~VizitMatrix()
{
	if (_data != nullptr)
		delete[] _data;
}

int FVM::Core::Vectorization::VizitMatrix::rows() const
{
	return _rows;
}

int FVM::Core::Vectorization::VizitMatrix::cols() const
{
	return _cols;
}

bool FVM::Core::Vectorization::VizitMatrix::is_visit(int row, int col) const
{
	return _data[row * _cols + col];
}

bool FVM::Core::Vectorization::VizitMatrix::is_all_visit() const
{
	return _count == 0;
}

void FVM::Core::Vectorization::VizitMatrix::visit(int row, int col)
{
	if(!_data[row * _cols + col])
	{
		_data[row * _cols + col] = true;
		_count--;
	}
}



FVM::Core::Vectorization::ColorPoint::ColorPoint() : Point(), Pixel()
{
}

FVM::Core::Vectorization::ColorPoint::ColorPoint(Point point, Pixel pixel) : Point(point), Pixel(pixel)
{
}

FVM::Core::Vectorization::DefaultVectorization::DefaultVectorization() : _image(nullptr), _vizit_matrix(nullptr)
{
}
