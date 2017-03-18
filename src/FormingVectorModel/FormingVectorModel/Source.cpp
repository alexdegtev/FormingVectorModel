#include <vector>

namespace Core
{
	namespace Transformations
	{
		class ITransformation;
	}

	namespace Vectorizations
	{
		class IVectorization;
	}
}


namespace Core
{
	namespace Objects
	{
		namespace Geometric
		{
			class IObject
			{
			public:
				virtual ~IObject()
				{
				}
			};

			class IPoint : public IObject
			{
			public:
				virtual ~IPoint()
				{
				}

				virtual int x() = 0;
				virtual int y() = 0;
			};

			class ILine : public IObject
			{
			public:
				virtual ~ILine()
				{
				}

				virtual IPoint* begin() = 0;
				virtual IPoint* end() = 0;
			};
		}

		namespace Visual
		{
			class IColor
			{
			public:
				virtual ~IColor()
				{
				}

				virtual unsigned char red() = 0;
				virtual void red(unsigned char value) = 0;

				virtual unsigned char green() = 0;
				virtual void green(unsigned char value) = 0;

				virtual unsigned char blue() = 0;
				virtual void blue(unsigned char value) = 0;

				virtual unsigned char brightness() = 0;
				virtual void brightness(unsigned char value) = 0;
			};

			class IPixel : public Geometric::IPoint, public IColor
			{
			public:
				enum binary_state
				{
					turn_on = 0, // the pixels of interest (object)
					turn_off = 255 // background
				};

				virtual ~IPixel()
				{
				}
			};

			class IImage
			{
			public:
				virtual ~IImage()
				{
				}

				virtual size_t rows() = 0;
				virtual size_t cols() = 0;
				virtual IPixel* get(size_t row, size_t col) = 0;
				virtual void set(size_t row, size_t col, IPixel* value) = 0;
				virtual void transform(Transformations::ITransformation* transforamtion) = 0;
				virtual std::vector<Geometric::IObject*> vectorize(Vectorizations::IVectorization* vectorization) = 0;
			};
		}
	}

	namespace Transformations
	{
		class ITransformation
		{
		public:
			virtual ~ITransformation()
			{
			}

			virtual void execute(Objects::Visual::IImage* image) = 0;
		};

		class IGrayscalation : public ITransformation
		{
		public:
			virtual ~IGrayscalation()
			{
			}
		};

		class IBinarization : public ITransformation
		{
		public:
			virtual ~IBinarization()
			{
			}
		};

		class ISkeletization : public ITransformation
		{
		public:
			virtual ~ISkeletization()
			{
			}
		};
	}

	namespace Vectorizations
	{
		class IVectorization
		{
		public:
			virtual ~IVectorization()
			{
			}

			virtual std::vector<Objects::Geometric::IObject*> execute(Objects::Visual::IImage* image) = 0;
		};
	}

	namespace Common
	{
		class Functions
		{
		};
	}

	namespace IO
	{
		class Path
		{
		};

		class Reader;

		class Writer;
	}
}
