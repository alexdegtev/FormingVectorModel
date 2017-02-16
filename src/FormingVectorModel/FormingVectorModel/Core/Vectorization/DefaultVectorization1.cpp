#include "DefaultVectorization1.hpp"
#include "../Objects/Geometric/Line.hpp"

FVM::Core::Vectorization::DefaultVectorization1::DefaultVectorization1()
{
}

FVM::Core::Vectorization::DefaultVectorization1::~DefaultVectorization1()
{
	delete _visit_matrix;
}

std::vector<IObject*> FVM::Core::Vectorization::DefaultVectorization1::vectorizate(IImage* image)
{
	_image = image->copy();

	_visit_matrix = new VisitMatrix(image->rows(), image->cols());

	std::vector<IObject*> objects;

	Point *start = nullptr, *current = nullptr, *prev = nullptr;

	while (!_visit_matrix->is_all_visited())
	{
		if(!start)
		{
			current = start = find_first_not_visited();
			if(!start)
			{
				break;
			}
		}

		std::vector<Point*> neighbours = find_neighbours(current->x(), current->y());

		switch (neighbours.size())
		{
		case 0:
			break;

		case 1:
			_visit_matrix->visit(current->x(), current->y());

			if (prev == nullptr)
			{
				start = prev = current;
				current = neighbours[0];
			}
			else
			{
				objects.push_back(new Line(*start, *current));
				prev = nullptr;
				start = current = neighbours[0];
			}
			break;

		case 2:
			if(prev == nullptr)
			{
				start = prev = current;
				current = neighbours[0];
			}
			else
			{
				_visit_matrix->visit(current->x(), current->y());
				
				Point* next = neighbours[0] == prev ? neighbours[1] : neighbours[0];
				if(is_aligned(prev, current, next))
				{
					prev = current;
				}
				else
				{
					objects.push_back(new Line(*start, *current));
					start = prev = current;
				}
				current = next;
			}
			break;

		case 3:
			if(prev == nullptr)
			{
				start = prev = current;
				current = neighbours[0];
			}
			else
			{
				_visit_matrix->visit(current->x(), current->y());

				for (int i = 0; i < neighbours.size(); i++)
				{
					if (neighbours[i] == prev) continue;
					if(is_aligned(prev, current, neighbours[i]))
					{
						prev = current;
						current = neighbours[i];
					}
				}
			}
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			break;

		default:
			break;
		}

		//for (int i = 0; i < neighbours.size(); i++)
		//{
		//	delete neighbours[i];
		//	neighbours[i] = nullptr;
		//}
	}

	return objects;
}

Point* FVM::Core::Vectorization::DefaultVectorization1::find_first_not_visited()
{
	for (int i = 0; i < _image->rows(); i++)
	{
		for (int j = 0; j < _image->cols(); j++)
		{
			if(_image->pixel(i, j)->brightness() == 255 && !_visit_matrix->is_visited(i, j))
			{
				return new Point(i, j);
			}
			else
			{
				_visit_matrix->visit(i, j);
			}
		}
	}

	return nullptr;
}

std::vector<Point*> FVM::Core::Vectorization::DefaultVectorization1::find_neighbours(int row, int col)
{
	std::vector<Point*> neighbours;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j==0) continue;

			Pixel *p = _image->pixel(row + i, col + j);
			//TODO: Нужно ли учитывать посещённые?
			if (p && p->brightness() == 255)
			{
				neighbours.push_back(new Point(row + i, col + j));
			}
		}
	}

	return neighbours;
}

bool FVM::Core::Vectorization::DefaultVectorization1::is_aligned(Point* a, Point* b, Point* c)
{
	return (a->x() - c->x()) * (b->y() - c->y()) == (b->x() - c->x()) * (a->y() - c->y());
}
