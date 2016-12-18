#ifndef FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION_HPP
#define FVM_CORE_VECTORIZATION_DEFAULTVECTORIZATION_HPP

#include "IVectorization.hpp"
#include "../Objects/Geometric/Point.hpp"

using namespace FVM::Core::Objects::Image;
using namespace FVM::Core::Objects::Geometric;

namespace FVM
{
	namespace Core
	{
		namespace Vectorization
		{
			class ColorPoint : public Point, public Pixel
			{
			public:
				ColorPoint();
				ColorPoint(Point point, Pixel pixel);
			};

			class VizitMatrix
			{
			public:
				VizitMatrix(int rows, int cols);
				~VizitMatrix();

				int rows() const;
				int cols() const;

				bool is_visit(int row, int col) const;
				bool is_all_visit() const;
				void visit(int row, int col);

			private:
				bool *_data;
				int _rows;
				int _cols;
				int _count;
			};

			class DefaultVectorization : public IVectorization
			{
			public:
				DefaultVectorization();

				std::vector<Objects::Geometric::IObject*> vectorizate(IImage* image) override;

			private:
				IImage *_image;
				VizitMatrix *_vizit_matrix;

				std::vector<Point*> find_neighbours(int row, int col);
				bool is_on_straight_line(Point a, Point b, Point c) const;
				Point* find_first_not_visited();
			};
		}
	}
}
#endif
