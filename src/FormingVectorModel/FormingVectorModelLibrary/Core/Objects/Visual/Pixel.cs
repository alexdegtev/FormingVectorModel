using FormingVectorModelLibrary.Core.Objects.Geometric;

namespace FormingVectorModelLibrary.Core.Objects.Visual
{
    public class Pixel : IPixel
    {
        private IPoint point;
        private IColor color;

        public Pixel(int x, int y, byte red, byte green, byte blue)
        {
            point = new Point(x, y);
            color = new Color(red, green, blue);
        }

        public Pixel(IPoint point, IColor color)
        {
            this.point = point ?? new Point();
            this.color = color ?? new Color();
        }

        public int X => point.X;

        public int Y => point.Y;

        public byte Red
        {
            get { return color.Red; }
            set { color.Red = value; }
        }

        public byte Green
        {
            get { return color.Green; }
            set { color.Green = value; }
        }

        public byte Blue
        {
            get { return color.Blue; }
            set { color.Blue = value; }
        }

        public byte Brightness
        {
            get { return color.Brightness; }
            set { color.Brightness = value; }
        }
    }
}