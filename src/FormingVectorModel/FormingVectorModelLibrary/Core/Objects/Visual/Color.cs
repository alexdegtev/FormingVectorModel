using FormingVectorModelLibrary.Core.Common;

namespace FormingVectorModelLibrary.Core.Objects.Visual
{
    public class Color : IColor
    {
        public Color(byte red, byte green, byte blue)
        {
            Red = red;
            Green = green;
            Blue = blue;
        }

        public Color(byte brightness) : this(brightness, brightness, brightness) { }

        public Color() : this(0) { }

        public byte Red { get; set; }

        public byte Green { get; set; }

        public byte Blue { get; set; }

        public byte Brightness
        {
            get { return Functions.RgbToBrightness(Red, Green, Blue); }
            set { Red = Green = Blue = value; }
        }

        public enum BinaryColor
        {
            TurnOn = byte.MaxValue,
            TurnOff = byte.MinValue
        }
    }
}