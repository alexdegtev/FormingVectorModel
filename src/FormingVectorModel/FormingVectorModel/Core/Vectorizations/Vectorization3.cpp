#include "Vectorization3.h"
#include "../Objects/Geometric/Line.h"

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization3::execute(Objects::Visual::IImage* image)
{
	iwvm = new ImageWithVisitedMarks(image);
	vs = nullptr;
	std::vector<ImageWithVisitedMarks::Pixel*> special_pixels;

	while (iwvm->has_unvisited_pixels())
	{
		if (vs == nullptr)
		{
			ImageWithVisitedMarks::Pixel *p = iwvm->get_first_unvisited();
			if (p == nullptr)
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

		if(vs->neighbours().size() == 0)
		{
			continue;
		}

		vs->current()->state = ImageWithVisitedMarks::VisitState::visited;

		ImageWithVisitedMarks::Pixel *next;

		if(!vs->previous())
		{
			special_pixels.push_back(vs->current());

			next = vs->next()[0];

			for(auto i:vs->next())
			{
				if(i != next && i->state == ImageWithVisitedMarks::VisitState::unvisited)
				{
					i->state = ImageWithVisitedMarks::VisitState::excluded;
				}
			}

			vs->start(vs->current());
		}
		else
		{
			next = nullptr;

			add_special_point(&special_pixels);

			for(auto i:vs->next())
			{
				if(ImageWithVisitedMarks::is_aligned(vs->previous(), vs->current(), i))
				{
					next = i;
					break;
				}
			}

			if(!next)
			{
				add_object(new Objects::Geometric::Line(vs->start()->point, vs->current()->point), special_pixels);
				special_pixels.clear();

				if(vs->next().size() == 0)
				{
					vs = nullptr;
					continue;
				}
				else
				{
					vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
					next = vs->next()[0];
					special_pixels.push_back(vs->current());
					vs->start(vs->current());
				}
			}

			for(auto i:vs->next())
			{
				if(i != next && i->state == ImageWithVisitedMarks::VisitState::unvisited)
				{
					i->state = ImageWithVisitedMarks::VisitState::excluded;
				}
			}
		}

		vs->previous(vs->current());
		vs->current(next);
	}

	return objects;
}

void Core::Vectorizations::Vectorization3::add_object(Objects::Geometric::ILine* line, std::vector<ImageWithVisitedMarks::Pixel*> special_pixels)
{
	objects.push_back(line);

	iwvm->convert_all_excluded_to_unvisited();

	for(auto i:special_pixels)
	{
		for(auto n:iwvm->get_neighbours(i))
		{
			if(n->state == ImageWithVisitedMarks::VisitState::unvisited)
			{
				i->state = ImageWithVisitedMarks::VisitState::unvisited;
				break;
			}
		}
	}
}

void Core::Vectorizations::Vectorization3::add_special_point(std::vector<ImageWithVisitedMarks::Pixel*> *special_pixels)
{
	bool has_aligned = false;
	for (auto i : vs->neighbours())
	{
		if (i != vs->previous() && ImageWithVisitedMarks::is_aligned(vs->previous(), vs->current(), i))
		{
			has_aligned = true;
			break;
		}
	}

	bool has_horizontal_neighbours = false;
	if(iwvm->get_horizontal_neigbour(vs->previous(), vs->current()).size() != 0)
	{
		has_horizontal_neighbours = true;
	}

	bool need_to_add = false;
	if(has_horizontal_neighbours)
	{
		need_to_add = true;
	}
	else
	{
		if(!has_aligned)
		{
			need_to_add = true;
		}
	}

	if(need_to_add)
	{
		special_pixels->push_back(vs->current());
	}
}
