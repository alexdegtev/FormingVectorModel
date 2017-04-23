using System.Collections.Generic;
using System.Configuration;

namespace FormingVectorModelLibrary.Core.Objects.Geometric
{
    public class Line : ILine
    {
        public Line(IPoint begin, IPoint end)
        {
            Begin = begin ?? new Point();
            End = end ?? new Point();
        }

        public Line() : this(null, null) { }

        public IPoint Begin { get; }

        public IPoint End { get; }
    }
}