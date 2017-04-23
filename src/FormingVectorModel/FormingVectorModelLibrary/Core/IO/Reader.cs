using System;
using System.IO;
using System.Runtime.InteropServices;
using FormingVectorModelLibrary.Core.Objects.Visual;
using Emgu.CV;
using Emgu.CV.Structure;

namespace FormingVectorModelLibrary.Core.IO
{
    public static class Reader
    {
        public static Objects.Visual.IImage Read(string path)
        {
            Image<Bgr, Byte> rowImage = new Image<Bgr, Byte>(path);
            Objects.Visual.IImage image = new Objects.Visual.Image(rowImage.Rows, rowImage.Cols, rowImage.Data);
            return image;
        }
    }
}