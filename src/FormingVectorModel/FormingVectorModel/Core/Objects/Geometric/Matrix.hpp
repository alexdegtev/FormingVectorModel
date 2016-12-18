#ifndef FVM_CORE_OBJECTS_GEOMETRIC_POINT_HPP
#define FVM_CORE_OBJECTS_GEOMETRIC_POINT_HPP

#include "IObject.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Objects
		{
			namespace Geometric
			{
				template <class T>
				class Matrix
				{
				public:
					Matrix();
					Matrix(int rows, int cols);
					Matrix(int rows, int cols, T **array);
					Matrix(const Matrix& other);
					
					
				};
			}
		}
	}
}
#endif
