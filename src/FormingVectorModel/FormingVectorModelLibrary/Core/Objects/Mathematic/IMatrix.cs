using System.Collections;

namespace FormingVectorModelLibrary.Core.Objects.Mathematic
{
    public interface IMatrix<T> : IEnumerable
    {
        int Rows { get; }

        int Cols { get; }

        T this[int row, int col] { get; set; }
    }
}