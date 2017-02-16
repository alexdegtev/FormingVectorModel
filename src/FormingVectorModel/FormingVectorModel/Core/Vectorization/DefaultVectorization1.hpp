#ifndef FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION1_HPP
#define FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION1_HPP

#include "IVectorization.hpp"
#include "../Objects/Geometric/Point.hpp"
#include "../Common/Types/Matrix.hpp"

using namespace FVM::Core::Objects::Image;
using namespace FVM::Core::Objects::Geometric;

namespace FVM
{
	namespace Core
	{
		namespace Vectorization
		{
			class VisitMatrix
			{
			public:
				VisitMatrix(int rows, int cols) : _rows(rows), _cols(cols), _count(rows * cols)
				{
					_data = new bool[_rows * _cols];
					for (int i = 0; i < _rows * _cols; i++)
						_data[i] = false;
				}

				~VisitMatrix()
				{
					if (_data != nullptr)
						delete[] _data;
				}

				int rows() const
				{
					return _rows;
				}

				int cols() const
				{
					return _cols;
				}

				bool is_visited(int row, int col) const
				{
					return _data[row * _cols + col];
				}

				bool is_all_visited() const
				{
					return _count == 0;
				}

				void visit(int row, int col)
				{
					if (!_data[row * _cols + col])
					{
						_data[row * _cols + col] = true;
						_count--;
					}
				}

			private:
				bool *_data;
				int _rows;
				int _cols;
				int _count;
			};

			class DefaultVectorization1 : public IVectorization
			{
			public:
				DefaultVectorization1();
				~DefaultVectorization1();

				std::vector<Objects::Geometric::IObject*> vectorizate(IImage* image) override;

			private:
				IImage *_image;
				VisitMatrix *_visit_matrix;

				Point* find_first_not_visited();
				std::vector<Point*> find_neighbours(int row, int col);
				bool is_aligned(Point *a, Point *b, Point *c);
			};
		}
	}
}
#endif
