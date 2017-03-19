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

		private:
			Pixel* _data;
			int _rows;
			int _cols;
		};
	}
}