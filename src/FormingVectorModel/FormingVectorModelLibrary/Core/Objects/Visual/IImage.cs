using System.Collections;
using System.Collections.Generic;
using FormingVectorModelLibrary.Core.Transformation;

namespace FormingVectorModelLibrary.Core.Objects.Visual
{
    public interface IImage : IEnumerable
    {
        int Rows { get; }

        int Cols { get; }

        IColor this[int row, int col] { get; set; }

        byte[,,] Data { get; }

        void Transform(ITransformation transformation);

        IList<IColor> GetNeighboursByBrightness(int row, int col, byte brightness);
    }
}