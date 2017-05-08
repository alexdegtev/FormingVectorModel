#ifndef CORE_TRANSFORMATION_ITRANSFORMATION_H
#define CORE_TRANSFORMATION_ITRANSFORMATION_H

namespace Core
{
	namespace Objects
	{
		namespace Visual
		{
			class IImage;
		}
	}
}

namespace Core
{
	namespace Transformation
	{
		class ITransformation
		{
		public:
			virtual ~ITransformation()
			{
			}

			virtual void execute(Objects::Visual::IImage* image) = 0;
		};
	}
}

#endif
