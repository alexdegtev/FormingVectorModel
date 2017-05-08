#include "VectorizationState.h"

Core::Vectorization::VectorizationState::VectorizationState(ImageWithVisitedMarks* image) : _previous(nullptr), _current(nullptr), _start(nullptr), _image(image)
{
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::VectorizationState::previous() const
{
	return _previous;
}

void Core::Vectorization::VectorizationState::previous(Core::Vectorization::ImageWithVisitedMarks::Pixel* value)
{
	_previous = value;
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::VectorizationState::current() const
{
	return _current;
}

void Core::Vectorization::VectorizationState::current(Core::Vectorization::ImageWithVisitedMarks::Pixel* value)
{
	_current = value;
}

Core::Vectorization::ImageWithVisitedMarks::Pixel* Core::Vectorization::VectorizationState::start() const
{
	return _start;
}

void Core::Vectorization::VectorizationState::start(Core::Vectorization::ImageWithVisitedMarks::Pixel* value)
{
	_start = value;
}

std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> Core::Vectorization::VectorizationState::neighbours() const
{
	return _neighbours;
}

void Core::Vectorization::VectorizationState::neighbours(std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> value)
{
	_neighbours = value;
}

std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> Core::Vectorization::VectorizationState::next()
{
	std::vector<Core::Vectorization::ImageWithVisitedMarks::Pixel*> result;

	for (auto point : _neighbours)
	{
		if (point != _previous && point->state == ImageWithVisitedMarks::VisitState::unvisited)
		{
			result.push_back(point);
		}
	}

	return result;
}

void Core::Vectorization::VectorizationState::reset()
{
	_current = nullptr;
	_previous = nullptr;
	_start = nullptr;
	_neighbours.clear();
}
