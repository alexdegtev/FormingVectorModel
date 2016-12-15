#ifndef FVM_CORE_OBJECTS_GEOMETRIC_POINT_HPP
#define FVM_CORE_OBJECTS_GEOMETRIC_POINT_HPP

#include "IObject.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Geometric
			{
				class Point : public IObject
				{
				public:
					Point();
					Point(int x, int y);
					Point(const Point& other);

					int x() const;
					int y() const;

					Point operator= (const Point& other);

				private:
					int x_;
					int y_;
				};
			}
		}
	}
}
#endif
