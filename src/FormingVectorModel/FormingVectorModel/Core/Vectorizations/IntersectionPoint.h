#pragma once

#include "../Objects/Geometric/IPoint.h"
#include <vector>

namespace Core
{
	namespace Vectorizations
	{
		class IntersectionPoint : public Objects::Geometric::IPoint
		{
		public:
			IntersectionPoint(IPoint *point);

			int x() const override;
			int y() const override;
			std::vector<IObject*> intersected_objects() const;
			void add_object(IObject *object);

		private:
			IPoint *_point;
			std::vector<IObject*> _intersected_objects;
		};
	}
}
