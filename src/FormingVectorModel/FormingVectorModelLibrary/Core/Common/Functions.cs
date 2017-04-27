using Emgu.CV;

namespace FormingVectorModelLibrary.Core.Common
{
    public static class Functions
    {
        public static byte RgbToBrightness(byte red, byte green, byte blue)
        {
            return (byte)(0.299 * red + 0.587 * green + 0.114 * blue);
        }

        public static void ImageToMat(Objects.Visual.IImage image, Mat mat)
        {
            for (int i = 0; i < image.Rows; i++)
            {
                for (int j = 0; j < image.Cols; j++)
                {
                    //if(mat.ConvertTo())
                }
            }
        }
    }
}