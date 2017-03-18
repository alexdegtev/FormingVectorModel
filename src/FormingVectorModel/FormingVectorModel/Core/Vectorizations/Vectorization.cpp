//#include "Vectorization.h"
//#include "../Objects/Visual/IImage.h"
//#include "../Objects/Geometric/Point.h"
//#include "../Objects/Geometric/Line.h"
//#include "../Common/Functions.h"
//
////Core::Vectorizations::PointWithState::PointWithState() : PointWithState(0, 0)
////{
////}
////
////Core::Vectorizations::PointWithState::PointWithState(int x, int y) : _point(new Objects::Geometric::Point(x, y))
////{
////}
////
////Core::Vectorizations::PointWithState::~PointWithState()
////{
////	if (_point)
////		delete _point;
////}
////
////int Core::Vectorizations::PointWithState::x()
////{
////	return _point->x();
////}
////
////int Core::Vectorizations::PointWithState::y()
////{
////	return _point->y();
////}
////
////Core::Vectorizations::PointWithState::State Core::Vectorizations::PointWithState::state()
////{
////	return _state;
////}
////
////void Core::Vectorizations::PointWithState::state(State value)
////{
////	_state = value;
////}
//
////Core::Vectorizations::ImageWithVisitedMarks::ImageWithVisitedMarks() : ImageWithVisitedMarks(nullptr)
////{
////}
////
////Core::Vectorizations::ImageWithVisitedMarks::ImageWithVisitedMarks(Objects::Visual::IImage* image) : _rows(image->rows()), _cols(image->cols())
////{
////	_data = new Pixel[_rows * _cols];
////
////	for (int i = 0; i < _rows; i++)
////	{
////		for (int j = 0; j < _cols; j++)
////		{
////			_data[i * _cols + j] = {image->get(i, j), new Objects::Geometric::Point(i, j), VisitState::unvisited};
////		}
////	}
////}
////
////Core::Vectorizations::ImageWithVisitedMarks::~ImageWithVisitedMarks()
////{
////	for (int i = 0; i < _rows * _cols; i++)
////	{
////		delete _data[i].point;
////	}
////
////	if (_data)
////		delete[] _data;
////}
////
////int Core::Vectorizations::ImageWithVisitedMarks::rows() const
////{
////	return _rows;
////}
////
////int Core::Vectorizations::ImageWithVisitedMarks::cols() const
////{
////	return _cols;
////}
////
////Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::get(int row, int col) const
////{
////	if (row < _rows && col < _cols)
////		return &_data[row * _cols + col];
////	else
////		throw "index out of range";
////}
////
////void Core::Vectorizations::ImageWithVisitedMarks::set(int row, int col, Pixel* value)
////{
////	if (row < _rows && col < _cols)
////		_data[row * _cols + col] = {value->color, value->point, value->state};
////	else
////		throw "index out of range";
////}
////
////void Core::Vectorizations::ImageWithVisitedMarks::convert_all_excluded_to_unvisited()
////{
////	for (int i = 0; i < _rows * _cols; i++)
////	{
////		if (_data[i].state == VisitState::excluded)
////		{
////			_data[i].state = VisitState::unvisited;
////		}
////	}
////}
////
////Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::get_first_unvisited()
////{
////	for (int i = 0; i < _rows * _cols; i++)
////	{
////		if (_data[i].state == VisitState::unvisited)
////		{
////			if (_data[i].color->brightness() == Objects::Visual::IColor::binary_color::turn_on)
////			{
////				return &_data[i];
////			}
////			else
////			{
////				_data[i].state = VisitState::visited;
////			}
////		}
////	}
////
////	return nullptr;
////}
////
////std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::ImageWithVisitedMarks::get_neighbours(Pixel* central)
////{
////	int row = central->point->x();
////	int col = central->point->y();
////
////	std::vector<Pixel*> neighbours;
////
////	for (int i = -1; i <= 1; i++)
////	{
////		for (int j = -1; j <= 1; j++)
////		{
////			if (i == 0 && j == 0) continue;
////
////			int index = (row + i) * _cols + (col + j);
////			if (0 <= row + i && row + i < _rows && 0 <= col + j && col + j < _cols &&
////				_data[index].color->brightness() == Objects::Visual::IColor::binary_color::turn_on &&
////				_data[index].state != VisitState::excluded)
////			{
////				neighbours.push_back(&_data[index]);
////			}
////		}
////	}
////
////	return neighbours;
////}
////
////bool Core::Vectorizations::ImageWithVisitedMarks::has_unvisited_pixels() const
////{
////	for (int i = 0; i < _rows * _cols; i++)
////	{
////		if (_data[i].state == VisitState::unvisited)
////		{
////			return true;
////		}
////	}
////
////	return false;
////}
////
////Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::ImageWithVisitedMarks::vertical_or_horizontal_neighbour(Pixel* central, std::vector<Pixel*> neighbours)
////{
////	Objects::Geometric::IPoint* c = central->point;
////	for (auto neighbour : neighbours)
////	{
////		Objects::Geometric::IPoint *n = neighbour->point;
////		if (c->x() + 1 == n->x() && c->y() == n->y() ||
////			c->x() - 1 == n->x() && c->y() == n->y() ||
////			c->x() == n->x() && c->y() + 1 == n->y() ||
////			c->x() == n->x() && c->y() - 1 == n->y())
////		{
////			return neighbour;
////		}
////	}
////
////	return nullptr;
////}
//
//Core::Vectorizations::VectorizationState::VectorizationState(ImageWithVisitedMarks* image) : _previous(nullptr), _current(nullptr), _start(nullptr), _image(image)
//{
//}
//
//Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::VectorizationState::previous() const
//{
//	return _previous;
//}
//
//void Core::Vectorizations::VectorizationState::previous(Core::Vectorizations::ImageWithVisitedMarks::Pixel* value)
//{
//	_previous = value;
//}
//
//Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::VectorizationState::current() const
//{
//	return _current;
//}
//
//void Core::Vectorizations::VectorizationState::current(Core::Vectorizations::ImageWithVisitedMarks::Pixel* value)
//{
//	_current = value;
//}
//
//Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::VectorizationState::start() const
//{
//	return _start;
//}
//
//void Core::Vectorizations::VectorizationState::start(Core::Vectorizations::ImageWithVisitedMarks::Pixel* value)
//{
//	_start = value;
//}
//
//std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::VectorizationState::neighbours() const
//{
//	return _neighbours;
//}
//
//void Core::Vectorizations::VectorizationState::neighbours(std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> value)
//{
//	_neighbours = value;
//}
//
//std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::VectorizationState::next()
//{
//	std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> result;
//
//	for (auto point : _neighbours)
//	{
//		if (point != _previous && point->state == VisitState::unvisited)
//		{
//			result.push_back(point);
//		}
//	}
//
//	return result;
//}
//
//std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization::execute(Objects::Visual::IImage* image)
//{
//	std::vector<Core::Objects::Geometric::IObject*> objects;
//	ImageWithVisitedMarks* iwvm = new ImageWithVisitedMarks(image);
//	VectorizationState* vs = nullptr;
//
//	while (iwvm->has_unvisited_pixels())
//	{
//		if (vs == nullptr)
//		{
//			vs = new VectorizationState(iwvm);
//			ImageWithVisitedMarks::Pixel* first_unvisited = iwvm->get_first_unvisited();
//			if (first_unvisited != nullptr)
//			{
//				vs->current(first_unvisited);
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		vs->neighbours(iwvm->get_neighbours(vs->current()));
//
//		switch (vs->neighbours().size())
//		{
//		case 1:
//			if (vs->previous() == nullptr)
//			{
//				vs->current()->state = VisitState::visited;
//				vs->previous(vs->current());
//				vs->start(vs->current());
//				vs->current(vs->next()[0]);
//				continue;
//			}
//			else
//			{
//				iwvm->convert_all_excluded_to_unvisited();
//				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
//				vs->current()->state = VisitState::visited;
//				//vs = nullptr;	//TODO: Плохо. vs->current() м.б. начальной точкой следующего отрезка.
//				continue;
//			}
//			break;
//
//		case 2:
//			if (vs->previous() == nullptr)
//			{
//				vs->current()->state = VisitState::visited;
//				vs->previous(vs->current());
//				vs->start(vs->current());
//
//				ImageWithVisitedMarks::Pixel *neighbour = ImageWithVisitedMarks::vertical_or_horizontal_neighbour(vs->current(), vs->next());
//				vs->current(neighbour == nullptr ? vs->next()[0] : neighbour);
//
//				for(auto n : vs->next())
//				{
//					if(n != vs->current())
//					{
//						n->state = VisitState::excluded;
//					}
//				}
//			}
//			else
//			{
//				if (Common::Functions::is_aligned(vs->previous()->point, vs->current()->point, vs->next()[0]->point))
//				{
//					vs->current()->state = VisitState::visited;
//					vs->previous(vs->current());
//					vs->current(vs->next()[0]);
//				}
//				else
//				{
//					objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
//					vs->current()->state = VisitState::visited;
//					vs->previous(vs->current());
//					vs->start(vs->current());
//					vs->current(vs->next()[0]);
//				}
//			}
//			break;
//		}
//	}
//
//	if (iwvm)
//		delete iwvm;
//
//	if (vs)
//		delete vs;
//
//	return objects;
//}
