#pragma once
#include "ImageWithVisitedMarks.h"

namespace Core
{
	namespace Vectorizations
	{
		class VectorizationState
		{
		public:
			VectorizationState(ImageWithVisitedMarks* image);

			ImageWithVisitedMarks::Pixel* previous() const;
			void previous(ImageWithVisitedMarks::Pixel* value);

			ImageWithVisitedMarks::Pixel* current() const;
			void current(ImageWithVisitedMarks::Pixel* value);

			ImageWithVisitedMarks::Pixel* start() const;
			void start(ImageWithVisitedMarks::Pixel* value);

			std::vector<ImageWithVisitedMarks::Pixel*> neighbours() const;
			void neighbours(std::vector<ImageWithVisitedMarks::Pixel*> value);

			std::vector<ImageWithVisitedMarks::Pixel*> next();

			void reset();

		private:
			ImageWithVisitedMarks::Pixel* _previous;
			ImageWithVisitedMarks::Pixel* _current;
			ImageWithVisitedMarks::Pixel* _start;
			std::vector<ImageWithVisitedMarks::Pixel*> _neighbours;
			ImageWithVisitedMarks* _image;
		};
	}
}