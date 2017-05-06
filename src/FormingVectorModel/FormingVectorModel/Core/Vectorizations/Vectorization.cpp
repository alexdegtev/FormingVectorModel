#include "Vectorization.h"
#include "VectorizationState.h"
#include "../Objects/Geometric/Line.h"
#include "../Common/Functions.h"

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization::execute(Objects::Visual::IImage* image)
{
	VectorizationState *vs = nullptr;
	ImageWithVisitedMarks *image_ = new ImageWithVisitedMarks(image);
	std::vector<Core::Objects::Geometric::IObject*> objects;

	while (image_->has_unvisited_pixels())
	{
		if(vs == nullptr)
		{
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
				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				delete vs;
				vs = nullptr;
			}

			continue;
		}

		if(vs->previous() == nullptr)
		{
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
				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
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

			if(!is_next_pixel_aligned)
			{
				objects.push_back(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
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
