#ifndef CORE_OBJECTS_GEOMETRIC_LINE_H
#define CORE_OBJECTS_GEOMETRIC_LINE_H

#include "ILine.h"
#include "Point.h"
#include <vector>
#include <set>

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class Line : public ILine
			{
			public:
				Line();
				Line(IPoint* begin, IPoint* end);
				Line(IPoint* begin, IPoint* end, std::vector<IPoint*> special_point);
				Line(Point begin, Point end);
				Line(IPoint* begin, IPoint* end, std::vector<Vectorization::IntersectionPoint*> intersections);
				Line(IPoint* begin, IPoint* end, std::set<Vectorization::IntersectionPoint*> intersections);
				~Line();

				IPoint* begin() const override;
				IPoint* end() const override;

				std::string to_string() override;

			private:
				IPoint* _begin;
				IPoint* _end;
				std::vector<Vectorization::IntersectionPoint*> intersections_;
			};
		}
	}
}

#endif
