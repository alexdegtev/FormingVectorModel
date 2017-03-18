#ifndef CORE_OBJECTS_GEOMETRIC_POINT_H
#define CORE_OBJECTS_GEOMETRIC_POINT_H

#include "IPoint.h"

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class Point : public IPoint
			{
			public:
				Point();
				Point(int x, int y);
				Point(IPoint* other);
				Point(const Point& other);

				int x() const override;
				int y() const override;

			private:
				int _x;
				int _y;
			};
		}
	}
}

#endif
