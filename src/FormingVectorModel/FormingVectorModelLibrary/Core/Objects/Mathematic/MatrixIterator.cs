using System.Collections;

namespace FormingVectorModelLibrary.Core.Objects.Mathematic
{
    public class MatrixIterator<T> : IEnumerator
    {
        private IMatrix<T> matrix;
        private int rowIndex = -1;
        private int colIndex = -1;

        public MatrixIterator(IMatrix<T> matrix)
        {
            this.matrix = matrix;
        }

        public bool MoveNext()
        {
            if (rowIndex == matrix.Rows - 1 && colIndex == matrix.Cols - 1)
            {
                Reset();
                return false;
            }
            else if (rowIndex == matrix.Rows - 1 && colIndex != matrix.Cols - 1)
            {
                colIndex++;
            }
            else if (rowIndex != matrix.Rows - 1 && colIndex == matrix.Cols - 1)
            {
                rowIndex++;
                colIndex = 0;
            }
            else if (rowIndex != matrix.Rows - 1 && colIndex != matrix.Cols - 1)
            {
                if (rowIndex == -1)
                {
                    rowIndex++;
                }
                colIndex++;
            }
            return true;
        }

        public void Reset()
        {
            rowIndex = -1;
            colIndex = -1;
        }

        public object Current => matrix[rowIndex, colIndex];
    }
}