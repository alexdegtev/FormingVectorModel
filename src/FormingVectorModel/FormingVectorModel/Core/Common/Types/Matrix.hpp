#ifndef FVM_CORE_COMMON_TYPES_MATRIX_HPP
#define FVM_CORE_COMMON_TYPES_MATRIX_HPP

#include "Array.hpp"

namespace FVM
{
	namespace Core
	{
		namespace Common
		{
			namespace Types
			{
				template <class _T, size_t...> class Matrix;

				template <class _T, size_t _rows, size_t _cols>
				class Matrix<_T, _rows, _cols>
				{
				private:
					Array<_T>* data;
				};

				template <class _T>
				class Matrix<_T>
				{
				public:
					Matrix() : Matrix(0, 0) { }

					Matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols)
					{
						_data = new Array<_T>(_rows * _cols);
					}

					Matrix(const Matrix& other) : _rows(other._rows), _cols(other._cols)
					{
						_data = new Array<_T>(other._data);
					}

					int rows() const
					{
						return _rows;
					}

					int cols() const
					{
						return _cols;
					}

					Matrix& operator=(const Matrix& other)
					{
						if(this != &other)
						{
							if (_data != nullptr)
								delete _data;

							_rows = other._rows;
							_cols = other._cols;
							_data = new Array<_T>(other._data);
						}
						return *this;
					}

					_T& operator[](int index)
					{
						return _data[index];
					}

				private:
					Array<_T>* _data;
					size_t _rows;
					size_t _cols;
				};
			}
		}
	}
}
#endif
