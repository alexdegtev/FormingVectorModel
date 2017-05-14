#ifndef CORE_OBJECTS_VISUAL_DRAWING_H
#define CORE_OBJECTS_VISUAL_DRAWING_H

#include "vector"
#include "../Geometric/ILine.h"

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class Drawing
			{
			public:
				Drawing(std::vector<Geometric::ILine*> front_view, std::vector<Geometric::ILine*> top_view, std::vector<Geometric::ILine*> side_view);
				Drawing();

				std::vector<Geometric::ILine*> front_view() const;
				void front_view(std::vector<Geometric::ILine*> value);

				std::vector<Geometric::ILine*> top_view() const;
				void top_view(std::vector<Geometric::ILine*> value);

				std::vector<Geometric::ILine*> side_view() const;
				void side_view(std::vector<Geometric::ILine*> value);

			private:
				std::vector<Geometric::ILine*> front_view_;
				std::vector<Geometric::ILine*> top_view_;
				std::vector<Geometric::ILine*> side_view_;
			};
		}
	}
}

#endif
