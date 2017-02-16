#ifndef FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION2_HPP
#define FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION2_HPP

#include "IVectorization.hpp"
#include "../Objects/Geometric/Point.hpp"
#include "../Objects/Geometric/Line.hpp"

using namespace FVM::Core::Objects::Image;
using namespace FVM::Core::Objects::Geometric;

namespace FVM
{
	namespace Core
	{
		namespace Vectorization
		{
			class PointWithState : public IPoint, public IPixel
			{
			public:
				enum State
				{
					visited,
					not_visited,
					excluded
				};

				PointWithState() : PointWithState(Point(), Pixel()) { }
				PointWithState(Point point, Pixel pixel) : m_point(point), m_pixel(pixel), m_state(State::not_visited) { }

				State state() const { return m_state; }
				void state(State state) { m_state = state; }
				unsigned char red() override { return m_pixel.red(); }
				void red(unsigned char value) override { m_pixel.red(value); }
				unsigned char green() override { return m_pixel.green(); }
				void green(unsigned char value) override { m_pixel.green(value); }
				unsigned char blue() override { return m_pixel.blue(); }
				void blue(unsigned char value) override { m_pixel.blue(value); }
				unsigned char brightness() override { return m_pixel.brightness(); }
				void brightness(unsigned char value) override { m_pixel.brightness(value); }
				int x() override { return m_point.x(); }
				int y() override { return m_point.y(); }
				Point get_point() { return m_point; }
				Pixel get_pixel() { return m_pixel; }

			private:
				Point m_point;
				Pixel m_pixel;
				State m_state;
			};

			class State
			{
			public:
				State() : _start(nullptr), _prev(nullptr), _current(nullptr) { }

				PointWithState* start() const { return _start; }
				void start(PointWithState* start) { _start = start; }

				PointWithState* prev() const { return _prev; }
				void prev(PointWithState* prev) { _prev = prev; }

				PointWithState* current() const { return _current; }
				void current(PointWithState* current) { _current = current; }

				std::vector<PointWithState*> neighbours() const { return _neighbours; }
				void neighbours(std::vector<PointWithState*> neighbours) { _neighbours = neighbours; }
				int neighboursCount() const { return _neighbours.size(); }

				std::vector<PointWithState*> next() const
				{
					std::vector<PointWithState*> result;

					result = _neighbours;
					for (int i = 0; i < result.size(); i++)
					{
						if (result[i] == _prev)
						{
							result.erase(result.begin() + i);
							break;
						}
					}

					return result;
				}

			private:
				PointWithState* _start;
				PointWithState* _prev;
				PointWithState* _current;
				std::vector<PointWithState*> _neighbours;
			};

			class ImageMatrixWithState
			{
			public:
				ImageMatrixWithState(IImage *image) : _image(image), _rows(image->rows()), _cols(image->cols()), _unvisited_count(_rows * _cols)
				{

					_data = new PointWithState[_rows * _cols];
					for (int i = 0; i < image->rows(); i++)
					{
						for (int j = 0; j < image->cols(); j++)
						{
							_data[i * image->cols() + j] = PointWithState(Point(i, j), *image->pixel(i, j));
						}
					}
				}
				~ImageMatrixWithState()
				{
					delete[] _data;
				}
				PointWithState* get(int row, int col) const
				{
					return &_data[row * _cols + col];
				}
				void set(int row, int col, PointWithState* value)
				{
					_data[row * _cols + col] = *value;
				}
				void visit(int row, int col)
				{
					if(_data[row * _cols + col].state() == PointWithState::State::not_visited)
					{
						_data[row * _cols + col].state(PointWithState::visited);
						_unvisited_count--;
					}
				}
				void visit(PointWithState* point)
				{
					visit(point->x(), point->y());
				}
				bool is_visit(int row, int col) const
				{
					return _data[row * _cols + col].state() == PointWithState::State::visited;
				}
				bool is_all_visited() const
				{
					return _unvisited_count == 0;
				}
				PointWithState* find_first_not_visited()
				{
					for (int i = 0; i < _rows; i++)
					{
						for (int j = 0; j < _cols; j++)
						{
							int index = i * _cols + j;
							if (_data[index].brightness() == 255 && _data[index].state() == PointWithState::State::not_visited)
							{
								return &_data[index];
							}
							else
							{
								visit(i, j);
							}
						}
					}
					return nullptr;
				}
				std::vector<PointWithState*> find_neighbours(PointWithState* point)
				{
					std::vector<PointWithState*> neighbours;

					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (i == 0 && j == 0) continue;

							Pixel *p = _image->pixel(point->x() + i, point->y() + j);
							if (p && p->brightness() == 255)
							{
								PointWithState* ps= &_data[(point->x() + i) * _cols + (point->y() + j)];
								if(ps->state() != PointWithState::State::excluded)
									neighbours.push_back(ps);
							}
						}
					}

					return neighbours;
				}
				void all_excluded_to_unvisit()
				{
					for (int i = 0; i < _rows * _cols; i++)
					{
						if(_data[i].state() == PointWithState::State::excluded)
						{
							_data[i].state(PointWithState::State::not_visited);
						}
					}
				}

			private:
				IImage* _image;
				int _rows;
				int _cols;
				PointWithState *_data;
				int _unvisited_count;
			};

			class DefaultVectorization2 : public IVectorization
			{
			public:
				DefaultVectorization2(){}
				~DefaultVectorization2(){}

				std::vector<Objects::Geometric::IObject*> vectorizate(IImage* image) override
				{
					ImageMatrixWithState *img = new ImageMatrixWithState(image);
					State* state = nullptr;
					std::vector<Objects::Geometric::IObject*> objects;

					while (!img->is_all_visited())
					{
						if(state == nullptr)
						{
							state = find_new_state(img);
							if (state == nullptr)
								break;
						}

						state->neighbours(img->find_neighbours(state->current()));

						switch (state->neighboursCount())
						{
						case 0:
							break;

						case 1:
							img->visit(state->current());

							if(state->prev() == nullptr)
							{
								PointWithState* current = state->current();
								state->current(state->next()[0]);
								state->prev(current);
								state->start(current);
							}
							else
							{
								objects.push_back(new Line(state->start()->get_point(), state->current()->get_point()));
								img->all_excluded_to_unvisit();
								delete state;
								state = nullptr;
							}
							break;

						case 2:
						{
							int visited_count = 0;
							for (PointWithState* next : state->next())
							{
								if (next->state() == PointWithState::State::visited)
								{
									visited_count++;
								}
							}
							if (visited_count == state->next().size())
							{
								objects.push_back(new Line(state->start()->get_point(), state->current()->get_point()));
								img->visit(state->current());
								img->all_excluded_to_unvisit();
								delete state;
								state = nullptr;
								continue;
							}

							if (state->prev() == nullptr)
							{

								//state->prev(state->current());
								//state->start(state->current());

								////TODO: Создать точку пересечения (state.cur)

								//PointWithState* n = horizontal_or_vertical_point(state->current(), state->neighbours());
								//if (n != nullptr && n->state() == PointWithState::State::not_visited)
								//{
								//	state->current(n);

								//	for (PointWithState* i : state->neighbours())
								//		if(i != n)
								//			i->state(PointWithState::State::excluded);
								//}
								//else
								//{
								//	for (PointWithState* i : state->next())
								//	{
								//		if(i->state() == PointWithState::State::not_visited)
								//		{
								//			state->current(i);
								//			break;
								//		}
								//	}
								//}

								//int visited_count = 0;
								//for(PointWithState* i : state->next())
								//{
								//	if (i->state() == PointWithState::State::visited)
								//		visited_count++;
								//}
								//if (visited_count == state->next().size() - 1)
								//{
								//	state->current()->state(PointWithState::State::visited);
								//}
							}
							else
							{
								img->visit(state->current());
								if (is_aligned(
									state->prev()->get_point(),
									state->current()->get_point(),
									state->next()[0]->get_point()
								))
								{
									PointWithState* current = state->current();
									state->current(state->next()[0]);
									state->prev(current);
								}
								else
								{
									objects.push_back(new Line(state->start()->get_point(), state->current()->get_point()));
									img->all_excluded_to_unvisit();

									//TODO: Создать точку пересечения (state.cur)

									PointWithState* current = state->current();
									state->current(state->next()[0]);
									state->prev(current);
									state->start(current);
								}
							}
							break;
						}
						case 3:
						{
							if (state->prev() == nullptr)
							{
								state->prev(state->current());
								state->start(state->current());

								int visited_count = 0;
								for (PointWithState* i : state->next())
								{
									if (i->state() == PointWithState::State::visited)
										visited_count++;
								}
								if (visited_count == state->next().size() - 1)
								{
									state->current()->state(PointWithState::State::visited);
								}

								PointWithState* n = horizontal_or_vertical_point(state->current(), state->neighbours());
								if (n != nullptr && n->state() == PointWithState::State::not_visited)
								{
									/*state->current(n);

									for (PointWithState* i : state->neighbours())
									{
										if (i != n)
										{
											i->state(PointWithState::State::excluded);
										}
									}*/
								}
								else
								{
									for (PointWithState* next : state->next())
									{
										if (next->state() == PointWithState::State::not_visited)
										{
											state->current(next);
											break;
										}
									}
								}
							}
							else
							{
								bool to_next_iter = false;
								for (PointWithState* next : state->next())
								{
									if (is_aligned(
										state->prev()->get_point(),
										state->current()->get_point(),
										next->get_point()
									) && next->state() == PointWithState::State::not_visited)
									{
										for (PointWithState* i : state->next())
										{
											if (next != i)
											{
												i->state(PointWithState::State::excluded);
											}
										}

										state->prev(state->current());
										state->current(next);
										to_next_iter = true;
									}
								}
								if (to_next_iter) continue;

								objects.push_back(new Line(state->start()->get_point(), state->current()->get_point()));
								img->all_excluded_to_unvisit();

								//TODO: Создать точку пересечения (state.cur)

								PointWithState* current = state->current();
								for (PointWithState* next : state->next())
								{
									if (next->state() == PointWithState::State::not_visited)
									{
										state->current(next);
										break;
									}
								}
								state->prev(current);
								state->start(current);
							}
							break;
						}
						default:
							break;
						}
					}


					delete img;
					if (state != nullptr)
						delete state;
					return objects;
				}

			private:
				State* find_new_state(ImageMatrixWithState *img)
				{
					PointWithState* first_not_visited = img->find_first_not_visited();
					if(first_not_visited == nullptr)
					{
						return nullptr;
					}

					State* new_state = new State();
					new_state->current(first_not_visited);
					return new_state;
				}

				bool is_aligned(Point a, Point b, Point c)
				{
					return (a.x() - c.x()) * (b.y() - c.y()) == (b.x() - c.x()) * (a.y() - c.y());
				}

				PointWithState* horizontal_or_vertical_point(PointWithState* center, std::vector<PointWithState*> neighbours)
				{
					for (int i = 0; i < neighbours.size(); i++)
					{
						Point c = center->get_point();
						Point n = neighbours[i]->get_point();
						if (c.x() + 1 == n.x() && c.y() == n.y() ||
							c.x() - 1 == n.x() && c.y() == n.y() ||
							c.x() == n.x() && c.y() + 1 == n.y() ||
							c.x() == n.x() && c.y() - 1 == n.y())
						{
							return neighbours[i];
						}
					}
					return nullptr;
				}
			};
		}
	}
}
#endif
