namespace FormingVectorModelLibrary.Core.Objects.Geometric
{
    public class Point : IPoint
    {
        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }

        public Point() : this(0, 0) { }

        public int X { get; set; }

        public int Y { get; set; }
    }
}