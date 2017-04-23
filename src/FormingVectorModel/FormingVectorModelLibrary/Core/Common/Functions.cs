namespace FormingVectorModelLibrary.Core.Common
{
    public static class Functions
    {
        public static byte RgbToBrightness(byte red, byte green, byte blue)
        {
            return (byte)(0.299 * red + 0.587 * green + 0.114 * blue);
        }
    }
}