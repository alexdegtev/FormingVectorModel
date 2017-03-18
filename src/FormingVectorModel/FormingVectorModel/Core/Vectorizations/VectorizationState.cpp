#include "VectorizationState.h"

Core::Vectorizations::VectorizationState::VectorizationState(ImageWithVisitedMarks* image) : _previous(nullptr), _current(nullptr), _start(nullptr), _image(image)
{
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::VectorizationState::previous() const
{
	return _previous;
}

void Core::Vectorizations::VectorizationState::previous(Core::Vectorizations::ImageWithVisitedMarks::Pixel* value)
{
	_previous = value;
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::VectorizationState::current() const
{
	return _current;
}

void Core::Vectorizations::VectorizationState::current(Core::Vectorizations::ImageWithVisitedMarks::Pixel* value)
{
	_current = value;
}

Core::Vectorizations::ImageWithVisitedMarks::Pixel* Core::Vectorizations::VectorizationState::start() const
{
	return _start;
}

void Core::Vectorizations::VectorizationState::start(Core::Vectorizations::ImageWithVisitedMarks::Pixel* value)
{
	_start = value;
}

std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::VectorizationState::neighbours() const
{
	return _neighbours;
}

void Core::Vectorizations::VectorizationState::neighbours(std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> value)
{
	_neighbours = value;
}

std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> Core::Vectorizations::VectorizationState::next()
{
	std::vector<Core::Vectorizations::ImageWithVisitedMarks::Pixel*> result;

	for (auto point : _neighbours)
	{
		if (point != _previous && point->state == ImageWithVisitedMarks::VisitState::unvisited)
		{
			result.push_back(point);
		}
	}

	return result;
}

void Core::Vectorizations::VectorizationState::reset()
{
	_current = nullptr;
	_previous = nullptr;
	_start = nullptr;
	_neighbours.clear();
}
