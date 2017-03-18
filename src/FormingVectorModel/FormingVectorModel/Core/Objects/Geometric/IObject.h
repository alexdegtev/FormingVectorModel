#ifndef CORE_OBJECTS_GEOMETRIC_IOBJECT_H
#define CORE_OBJECTS_GEOMETRIC_IOBJECT_H

namespace Core
{
	namespace Vectorizations
	{
		class IntersectionPoint;
	}
}

namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class IObject
			{
			public:
				IObject() : _intersection_point(nullptr) {}
				virtual ~IObject()
				{
				}

				virtual Vectorizations::IntersectionPoint *intersection_point() const = 0;
				virtual void intersection_point(Vectorizations::IntersectionPoint *value) = 0;

			protected:
				Vectorizations::IntersectionPoint *_intersection_point;
			};
		}
	}
}

#endif
