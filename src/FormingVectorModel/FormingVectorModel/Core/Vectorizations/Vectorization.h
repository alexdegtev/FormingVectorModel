//#ifndef CORE_VECTORIZATIONS_VECTORIZATION_H
//#define CORE_VECTORIZATIONS_VECTORIZATION_H
//
//#include "IVectorization.h"
//#include "../Objects/Geometric/IPoint.h"
//#include "../Objects/Visual/IImage.h"
//
//namespace Core
//{
//	namespace Vectorizations
//	{
//
//
//		//class PointWithState : public Objects::Geometric::IPoint
//		//{
//		//public:
//		//	enum State
//		//	{
//		//		unvisited,
//		//		visited,
//		//		excluded
//		//	};
//		//	PointWithState();
//		//	PointWithState(int x, int y);
//		//	~PointWithState();
//		//	int x() override;
//		//	int y() override;
//		//	State state();
//		//	void state(State value);
//		//private:
//		//	Objects::Geometric::Point *_point;
//		//	State _state;
//		//};
//
//		class ImageWithVisitedMarks
//		{
//		public:
//			enum VisitState
//			{
//				unvisited,
//				visited,
//				excluded
//			};
//
//			struct Pixel
//			{
//				Objects::Visual::IColor* color;
//				Objects::Geometric::IPoint* point;
//				VisitState state;
//			};
//
//			ImageWithVisitedMarks();
//			ImageWithVisitedMarks(Objects::Visual::IImage* image);
//			~ImageWithVisitedMarks();
//
//			int rows() const;
//			int cols() const;
//			Pixel* get(int row, int col) const;
//			void set(int row, int col, Pixel* value);
//
//			void convert_all_excluded_to_unvisited();
//			Pixel* get_first_unvisited();
//			std::vector<Pixel*> get_neighbours(Pixel* central);
//			bool has_unvisited_pixels() const;
//			static Pixel *vertical_or_horizontal_neighbour(Pixel *central, std::vector<Pixel*> neighbours);
//
//		private:
//			Pixel* _data;
//			int _rows;
//			int _cols;
//		};
//
//		class VectorizationState
//		{
//		public:
//			VectorizationState(ImageWithVisitedMarks* image);
//
//			ImageWithVisitedMarks::Pixel* previous() const;
//			void previous(ImageWithVisitedMarks::Pixel* value);
//			ImageWithVisitedMarks::Pixel* current() const;
//			void current(ImageWithVisitedMarks::Pixel* value);
//			ImageWithVisitedMarks::Pixel* start() const;
//			void start(ImageWithVisitedMarks::Pixel* value);
//			std::vector<ImageWithVisitedMarks::Pixel*> neighbours() const;
//			void neighbours(std::vector<ImageWithVisitedMarks::Pixel*> value);
//			std::vector<ImageWithVisitedMarks::Pixel*> next();
//
//		private:
//			ImageWithVisitedMarks::Pixel* _previous;
//			ImageWithVisitedMarks::Pixel* _current;
//			ImageWithVisitedMarks::Pixel* _start;
//			std::vector<ImageWithVisitedMarks::Pixel*> _neighbours;
//			ImageWithVisitedMarks* _image;
//		};
//
//		class Vectorization : public IVectorization
//		{
//		public:
//			std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) override;
//		};
//	}
//}
//
//#endif
