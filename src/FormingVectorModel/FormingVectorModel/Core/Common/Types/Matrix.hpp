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
				template <class _T> class Matrix;

				template <class _T>
				class Matrix
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

					~Matrix()
					{
						delete _data;
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

					_T& operator()(size_t row, size_t col)
					{
						return (*_data)(row * _cols + col);
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
