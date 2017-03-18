#ifndef CORE_OBJECTS_GEOMETRIC_LINE_H
#define CORE_OBJECTS_GEOMETRIC_LINE_H

#include "ILine.h"
#include "Point.h"

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
				Line(Point begin, Point end);
				~Line();

				IPoint* begin() const override;
				IPoint* end() const override;

			private:
				IPoint* _begin;
				IPoint* _end;
			};
		}
	}
}

#endif
