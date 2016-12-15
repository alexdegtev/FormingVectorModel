#ifndef FVM_CORE_OBJECTS_GEOMETRIC_LINE_HPP
#define FVM_CORE_OBJECTS_GEOMETRIC_LINE_HPP

#include "IObject.hpp"
#include "Point.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Geometric
			{
				class Line : public IObject
				{
				public:
					Line();
					Line(Point p1, Point p2);
					Line(const Line& other);

					Point p1() const;
					Point p2() const;
					double length() const;

					Line operator= (const Line& other);

				private:
					Point p1_;
					Point p2_;
				};
			}
		}
	}
}
#endif
