#include "Vectorization.h"
#include "VectorizationState.h"
#include "../Objects/Geometric/Line.h"
#include "../Common/Functions.h"
#include "IntersectionPointsSet.h"
#include <set>

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorization::Vectorization::execute(Objects::Visual::IImage* image)
{
	VectorizationState *vs = nullptr;
	ImageWithVisitedMarks *image_ = new ImageWithVisitedMarks(image);
	std::vector<Objects::Geometric::IObject*> objects;
	IntersectionPointsSet *intersections = new IntersectionPointsSet();
	std::set<IntersectionPoint*> current_intersections_set;
	
	while (image_->has_unvisited_pixels())
	{
		if(vs == nullptr)
		{
			current_intersections_set.clear();

			image_->convert_all_excluded_to_unvisited();

			ImageWithVisitedMarks::Pixel *pixel = image_->get_first_unvisited();
			if (pixel != nullptr)
			{
				vs = new VectorizationState(image_);
				vs->current(pixel);
			}
			else
			{
				break;
			}
		}

		vs->neighbours(image_->get_neighbours(vs->current()));

		if (vs->neighbours().size() == 0)
		{
			vs->current()->state = ImageWithVisitedMarks::VisitState::visited;

			if(vs->previous() != nullptr)
			{
				current_intersections_set.insert(intersections->get(vs->current()->point));
				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point, current_intersections_set));
				current_intersections_set.clear();
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				delete vs;
				vs = nullptr;
			}

			continue;
		}

		if(vs->previous() == nullptr)
		{
			current_intersections_set.insert(intersections->get(vs->current()->point));

			std::vector<ImageWithVisitedMarks::Pixel*> nexts = vs->next();

			ImageWithVisitedMarks::Pixel *next = image_->get_horizontal_or_vertical_neighbour(vs->current(), nexts);
			if(next == nullptr)
			{
				next = nexts[0];
			}

			bool has_excluded = false;
			for(auto n : nexts)
			{
				if(n != next)
				{
					n->state = ImageWithVisitedMarks::VisitState::excluded;

					if(!has_excluded)
					{
						has_excluded = true;
					}
				}
			}

			vs->current()->state = has_excluded
				? ImageWithVisitedMarks::VisitState::excluded
				: ImageWithVisitedMarks::VisitState::visited;

			vs->start(vs->current());
			vs->previous(vs->current());
			vs->current(next);
		}
		else
		{
			std::vector<ImageWithVisitedMarks::Pixel*> nexts = vs->next();
			if(nexts.size() == 0)
			{
				current_intersections_set.insert(intersections->get(vs->current()->point));

				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point, current_intersections_set));
				current_intersections_set.clear();
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				delete vs;
				vs = nullptr;
				continue;
			}

			ImageWithVisitedMarks::Pixel* next = nullptr;
			bool is_next_pixel_aligned = false;
			for(auto n : nexts)
			{
				if(Common::Functions::is_aligned(vs->previous()->point, vs->current()->point, n->point))
				{
					next = n;
					is_next_pixel_aligned = true;
					break;
				}
			}
			if(next == nullptr)
			{
				next = nexts[0];
			}

			bool has_excluded = false;
			for (auto n : nexts)
			{
				if (n != next)
				{
					n->state = ImageWithVisitedMarks::VisitState::excluded;

					if (!has_excluded)
					{
						has_excluded = true;
					}
				}
			}


			vs->current()->state = has_excluded
				? ImageWithVisitedMarks::VisitState::excluded
				: ImageWithVisitedMarks::VisitState::visited;

			bool has_horizontal_neighbours = false;
			for(auto n : vs->neighbours())
			{
				if(image_->is_horizontal_neighbour(vs->previous(), vs->current(), n))
				{
					has_horizontal_neighbours = true;
					break;
				}
			}
			if (vs->current()->state == ImageWithVisitedMarks::VisitState::excluded || has_horizontal_neighbours)
			{
				current_intersections_set.insert(intersections->get(vs->current()->point));
			}

			if(!is_next_pixel_aligned)
			{
				IntersectionPoint* ip = intersections->get(vs->current()->point);
				current_intersections_set.insert(ip);

				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point, current_intersections_set));
				current_intersections_set.clear();
				vs->start(vs->current());
			}

			vs->previous(vs->current());
			vs->current(next);
		}
	}


	if (image_) delete image_;
	if (vs) delete vs;

	return objects;
}
