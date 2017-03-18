#include "Vectorization2.h"
#include "../Objects/Visual/IImage.h"
#include "../Objects/Geometric/Line.h"
#include "../Objects/Geometric/Point.h"
#include "../Common/Functions.h"

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization2::execute(Objects::Visual::IImage* image)
{
	iwvm = new ImageWithVisitedMarks(image);
	vs = nullptr;


	while (iwvm->has_unvisited_pixels())
	{
		if(vs == nullptr)
		{
			ImageWithVisitedMarks::Pixel *pixel = iwvm->get_first_unvisited();
			if(pixel)
			{
				vs = new VectorizationState(iwvm);
				vs->current(pixel);
			}
			else
			{
				break;
			}
		}
		else
		{
			if(!vs->current() && !vs->previous() && !vs->start())
			{
				ImageWithVisitedMarks::Pixel *pixel = iwvm->get_first_unvisited();
				if (pixel)
				{
					vs = new VectorizationState(iwvm);
					vs->current(pixel);
				}
				else
				{
					break;
				}
			}
		}

		vs->neighbours(iwvm->get_neighbours(vs->current()));

		switch (vs->neighbours().size())
		{
		case 1:
			if(!vs->previous())  // [1]
			{
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				vs->previous(vs->current());
				vs->start(vs->current());
				vs->current(vs->next()[0]);
			}
			else  // [3]
			{
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				add_object_with_resolving_dependences(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
				//vs = nullptr;
				vs->reset();
			}
			break;

		case 2:
			if(!vs->previous())
			{
				
			}
			else
			{
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				
				if(ImageWithVisitedMarks::is_aligned(vs->previous(), vs->current(), vs->next()[0]))  // [2]
				{
					vs->previous(vs->current());
					vs->current(vs->next()[0]);
				}
				else  // [4]
				{
					add_object_with_resolving_dependences(new Objects::Geometric::Line(vs->start()->point, vs->current()->point));
					vs->previous(vs->current()); 
					vs->start(vs->current());
					vs->current(vs->next()[0]);
				}
			}
			break;

		case 3:
			if(!vs->previous())
			{
				
			}
			else
			{
				//vs->current()->state = ImageWithVisitedMarks::VisitState::visited;

				ImageWithVisitedMarks::Pixel *neighbour = ImageWithVisitedMarks::find_aligned(vs->previous(), vs->current(), vs->next());
				if (neighbour == nullptr)
				{
					neighbour = vs->next()[0];
				}
				vs->previous(vs->current());
				vs->current(neighbour);

				for(auto n : vs->next())
				{
					if(n != neighbour)
					{
						n->state = ImageWithVisitedMarks::VisitState::excluded;
					}
				}
			}
			break;

		default: 
			break;
		}
	}


	if (iwvm)
		delete iwvm;
	if (vs)
		delete vs;

	return objects;
}

void Core::Vectorizations::Vectorization2::add_object_with_resolving_dependences(Objects::Geometric::ILine* line)
{
	objects.push_back(line);

	iwvm->convert_all_excluded_to_unvisited();
}
