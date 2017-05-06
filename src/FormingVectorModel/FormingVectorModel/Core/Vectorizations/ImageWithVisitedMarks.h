#pragma once
#include "../Objects/Visual/IColor.h"
#include "../Objects/Geometric/IPoint.h"
#include <vector>

#include "../Objects/Visual/IImage.h"

namespace Core
{
	namespace Vectorizations
	{
		class ImageWithVisitedMarks
		{
		public:
			enum VisitState
			{
				unvisited,
				visited,
				excluded
			};

			struct Pixel
			{
				Objects::Visual::IColor* color;
				Objects::Geometric::IPoint* point;
				VisitState state;
			};

			ImageWithVisitedMarks();
			ImageWithVisitedMarks(Objects::Visual::IImage* image);
			~ImageWithVisitedMarks();

			int rows() const;
			int cols() const;
			Pixel* get(int row, int col) const;
			void set(int row, int col, Pixel* value);

			void convert_all_excluded_to_unvisited();
			Pixel* get_first_unvisited();
			std::vector<Pixel*> get_neighbours(Pixel* central);
			std::vector<Pixel*> get_neighbours_with_excluded(Pixel* central);
			bool has_unvisited_pixels() const;
			static Pixel *vertical_or_horizontal_neighbour(Pixel *central, std::vector<Pixel*> neighbours);
			static bool is_aligned(Pixel *a, Pixel *b, Pixel *c);
			static Pixel *find_aligned(Pixel *previous, Pixel *central, std::vector<Pixel*> neighbours);
			std::vector<Pixel *> get_horizontal_neigbour(Pixel *previous, Pixel *center);
			static bool is_horizontal_neighbour(Pixel *previous, Pixel *center, Pixel *neighbour);
			static Pixel* get_horizontal_or_vertical_neighbour(Pixel *center, std::vector<Pixel*> neighbours)
			{
				for (auto n : neighbours) {
					if (center->point->x() + 1 == n->point->x() && center->point->y() == n->point->y() ||
						center->point->x() - 1 == n->point->x() && center->point->y() == n->point->y() ||
						center->point->x() == n->point->x() && center->point->y() + 1 == n->point->y() ||
						center->point->x() == n->point->x() && center->point->y() - 1 == n->point->y())
					{
						return n;
					}
				}
				return nullptr;
			}

		private:
			Pixel* _data;
			int _rows;
			int _cols;
		};
	}
}