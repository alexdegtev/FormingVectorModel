#include "Vectorization3.h"
#include "../Objects/Geometric/Line.h"

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization3::execute(Objects::Visual::IImage* image)
{
	iwvm = new ImageWithVisitedMarks(image);
	vs = nullptr;
	std::vector<ImageWithVisitedMarks::Pixel*> special_points;
	std::vector<ImageWithVisitedMarks::Pixel*> intersections;

	while(iwvm->has_unvisited_pixels())
	{
		if(vs == nullptr)
		{
			ImageWithVisitedMarks::Pixel *p = iwvm->get_first_unvisited();
			if(p == nullptr)
			{
				break;
			}
			else
			{
				vs = new VectorizationState(iwvm);
				vs->current(p);
			}
		}

		vs->neighbours(iwvm->get_neighbours(vs->current()));
		int neighbours_count = vs->neighbours().size();

		if(vs->previous() == nullptr)
		{
			if(neighbours_count == 1)
			{
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
			}
			else
			{
				special_points.push_back(vs->current());
				if(vs->next().size() <= 1)
				{
					vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				}
			}

			ImageWithVisitedMarks::Pixel *next = vs->next()[0];
			for (auto i : vs->next())
			{
				if(i!= next)
				{
					i->state = ImageWithVisitedMarks::VisitState::excluded;
				}
			}

			vs->previous(vs->current());
			vs->start(vs->current());
			vs->current(next);
		}
		else
		{
			if(neighbours_count == 1)
			{
				//TODO: special_point
				add_object(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
				iwvm->convert_all_excluded_to_unvisited();

				std::vector<ImageWithVisitedMarks::Pixel*> neighbours = iwvm->get_neighbours(vs->current());
				int unvisited_count = 0;
				for(auto i : neighbours)
				{
					if(i->state == ImageWithVisitedMarks::VisitState::unvisited)
					{
						unvisited_count++;
					}
				}
				if(unvisited_count == 0)
				{
					vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				}

				vs = nullptr;
				special_points.clear();
			}
			else
			{
				if(neighbours_count != 2)
				{
					special_points.push_back(vs->current());
				}

				ImageWithVisitedMarks::Pixel *next = nullptr;
				for(auto i:vs->next())
				{
					if(ImageWithVisitedMarks::is_aligned(vs->previous(), vs->current(), i))
					{
						next = i;
						break;
					}
				}
				if(next == nullptr)
				{
					add_object(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
					iwvm->convert_all_excluded_to_unvisited();

					std::vector<ImageWithVisitedMarks::Pixel*> neighbours = iwvm->get_neighbours(vs->current());
					int unvisited_count = 0;
					for (auto i : neighbours)
					{
						if (i->state == ImageWithVisitedMarks::VisitState::unvisited)
						{
							unvisited_count++;
						}
					}
					if (unvisited_count == 0)
					{
						vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
					}

					vs = nullptr;
					special_points.clear();
					continue;
				}

				for(auto i:vs->next())
				{
					if(i!=next)
					{
						i->state = ImageWithVisitedMarks::VisitState::excluded;
					}
				}

				//TODO: next уже изменён
				if(vs->next().size() == 1)
				{
					vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				}

				vs->previous(vs->current());
				vs->current(next);
			}
		}
	}

	return objects;
}

void Core::Vectorizations::Vectorization3::add_object(Objects::Geometric::ILine* line)
{
	objects.push_back(line);
}
