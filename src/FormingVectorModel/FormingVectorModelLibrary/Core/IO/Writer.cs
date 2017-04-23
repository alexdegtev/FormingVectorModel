using System;
using Emgu.CV;
using Emgu.CV.Structure;

namespace FormingVectorModelLibrary.Core.IO
{
    public class Writer
    {
        public static void Write(Objects.Visual.IImage image, string path)
        {
            Image<Bgr, Byte> rowImage = new Image<Bgr, Byte>(image.Data);
            rowImage.Save(path);
        }
    }
}