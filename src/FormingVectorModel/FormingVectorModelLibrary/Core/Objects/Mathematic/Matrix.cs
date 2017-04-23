using System;
using System.Collections;

namespace FormingVectorModelLibrary.Core.Objects.Mathematic
{
    public class Matrix<T> : IMatrix<T>
    {
        private T[] data;

        public Matrix(int rows, int cols)
        {
            if (rows <= 0 || cols <= 0)
            {
                throw new ArgumentException("Need positive 'rows' and 'cols' params.");
            }

            Rows = rows;
            Cols = cols;

            data = new T[Rows * Cols];
        }

        public Matrix() : this(0, 0) { }

        public int Rows { get; }

        public int Cols { get; }

        public T this[int row, int col]
        {
            get
            {
                if (row < 0 || row >= Rows || col < 0 || col >= Cols)
                {
                    throw new System.IndexOutOfRangeException();
                }

                return data[row * Cols + col];
            }
            set
            {
                if (row < 0 || row >= Rows || col < 0 || col >= Cols)
                {
                    throw new System.IndexOutOfRangeException();
                }

                data[row * Cols + col] = value;
            }
        }

        public IEnumerator GetEnumerator()
        {
            return new MatrixIterator<T>(this);
        }
    }
}