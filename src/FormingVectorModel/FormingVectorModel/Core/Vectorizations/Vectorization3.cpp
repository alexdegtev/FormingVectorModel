#include "Vectorization3.h"
#include "../Objects/Geometric/Line.h"

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization3::execute(Objects::Visual::IImage* image)
{

	iwvm = new ImageWithVisitedMarks(image);
	vs = nullptr;
	std::vector<Objects::Geometric::IPoint*> special_points;
	std::vector<ImageWithVisitedMarks::Pixel*> special_pixels;

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

		switch (neighbours_count)
		{
		case 0:
			break;

		case 1:
			special_points.push_back(vs->current()->point);
			vs->current()->state = ImageWithVisitedMarks::VisitState::visited;

			if(vs->previous() == nullptr)
			{
				vs->start(vs->current());
				vs->previous(vs->current());
				vs->current(vs->next()[0]);
			}
			else
			{
				add_object(new Objects::Geometric::Line(vs->start()->point, vs->current()->point, special_points));

				iwvm->convert_all_excluded_to_unvisited();
				special_points.clear();

				vs = nullptr;
			}
			break;

		case 2:
			if(vs->previous() == nullptr)
			{
				ImageWithVisitedMarks::Pixel *next = vs->next()[0];

				int unvisited_neighbours = 0;
				for(auto i:vs->next())
				{
					if(i->state == ImageWithVisitedMarks::VisitState::unvisited)
					{
						unvisited_neighbours++;
					}
				}
				if(unvisited_neighbours == 1)
				{
					vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				}

				if(vs->current()->state == ImageWithVisitedMarks::VisitState::visited)
				{
					for(auto i:vs->next())
					{
						if(i!= next)
						{
							i->state = ImageWithVisitedMarks::VisitState::excluded;
						}
					}
				}

				special_points.push_back(vs->current()->point);

				vs->start(vs->current());
				vs->previous(vs->current());
				vs->current(next);
			}
			else
			{
				vs->current()->state = ImageWithVisitedMarks::VisitState::visited;

				if(!ImageWithVisitedMarks::is_aligned(vs->previous(), vs->current(), vs->next()[0]))
				{
					add_object(new Objects::Geometric::Line(vs->start()->point, vs->current()->point, special_points));

					iwvm->convert_all_excluded_to_unvisited();
					special_points.clear();

					special_points.push_back(vs->current()->point);

					vs->start(vs->current());
				}

				vs->previous(vs->current());
				vs->current(vs->next()[0]);
			}
			break;

		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			{
				int unvisited_neighbours_count = 0;
				for (auto i : vs->neighbours())
				{
					if (i->state == ImageWithVisitedMarks::VisitState::unvisited)
					{
						unvisited_neighbours_count++;
					}
				}
				if (unvisited_neighbours_count == 1)
				{
					vs->current()->state = ImageWithVisitedMarks::VisitState::visited;
				}

				special_points.push_back(vs->current()->point);

				ImageWithVisitedMarks::Pixel *next;

				if (vs->previous() == nullptr)
				{
					next = vs->next()[0];

					if (vs->current()->state == ImageWithVisitedMarks::VisitState::visited)
					{
						for (auto i : vs->next())
						{
							if (i != next)
							{
								i->state = ImageWithVisitedMarks::VisitState::excluded;
							}
						}
					}

					vs->start(vs->current());
				}
				else
				{
					next = nullptr;

					for (auto i : vs->next())
					{
						if (ImageWithVisitedMarks::is_aligned(vs->previous(), vs->current(), i))
						{
							next = i;
							break;
						}
					}

					if (next == nullptr)
					{
						next = vs->next()[0];

						add_object(new Objects::Geometric::Line(vs->start()->point, vs->current()->point, special_points));
						iwvm->convert_all_excluded_to_unvisited();
						special_points.clear();

						special_points.push_back(vs->current()->point);

						vs->start(vs->current());
					}

					for (auto i : vs->next())
					{
						if (i != next)
						{
							i->state = ImageWithVisitedMarks::VisitState::excluded;
						}
					}
				}

				vs->previous(vs->current());
				vs->current(next);
			}
			break;

		default:
			break;
		}
	}

	return objects;
}

std::vector<Core::Objects::Geometric::IObject*> Core::Vectorizations::Vectorization3::execute1(Objects::Visual::IImage* image)
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
