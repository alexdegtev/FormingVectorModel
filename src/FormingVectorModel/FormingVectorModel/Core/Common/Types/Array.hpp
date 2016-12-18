#ifndef FVM_CORE_COMMON_TYPES_ARRAY_HPP
#define FVM_CORE_COMMON_TYPES_ARRAY_HPP

namespace FVM
{
	namespace Core
	{
		namespace Common
		{
			namespace Types
			{
				template <class, size_t...> class Array;

				template <class _T, size_t _size>
				class Array<_T, _size>
				{
				public:
					Array()
					{
						_data = _size > 0 ? new _T[_size] : nullptr;
					}

					Array(const Array& other)
					{
						if (_size > 0)
						{
							_data = new _T[_size];
							for (int i = 0; i < _size; i++)
								_data[i] = other._data[i];
						}
						else
							_data = nullptr;
					}

					~Array()
					{
						if (_data != nullptr)
							delete[] _data;
					}

					size_t size() const
					{
						return _size;
					}

					Array& operator=(const Array& other)
					{
						if (this != &other)
						{
							if (_data != nullptr)
								delete[] _data;

							if (_size > 0) {
								_data = new _T[_size];
								for (int i = 0; i < _size; i++)
									_data[i] = other._data[i];
							}
							else
								_data = nullptr;
						}
						return *this;
					}

					_T& operator[](size_t index)
					{
						return _data[index];
					}

				private:
					_T* _data;
				};

				template <class _T>
				class Array<_T>
				{
				public:
					Array() : Array(0) { }

					Array(size_t size) : _size(size)
					{
						_data = _size > 0 ? new _T[_size] : nullptr;
					}

					Array(const Array& other) : _size(other._size)
					{
						if (_size > 0)
						{
							_data = new _T[_size];
							for (int i = 0; i < _size; i++)
								_data[i] = other._data[i];
						}
						else
							_data = nullptr;
					}

					~Array()
					{
						if (_data != nullptr)
							delete[] _data;
					}

					size_t size() const
					{
						return _size;
					}

					Array& operator=(const Array& other)
					{
						if (this != &other)
						{
							if (_data != nullptr)
								delete[] _data;

							_size = other._size;

							if (_size > 0) {
								_data = new _T[_size];
								for (int i = 0; i < _size; i++)
									_data[i] = other._data[i];
							}
							else
								_data = nullptr;
						}
						return *this;
					}

					_T& operator[](size_t index)
					{
						return _data[index];
					}

				private:
					_T* _data;
					size_t _size;
				};
			}
		}
	}
}
#endif
