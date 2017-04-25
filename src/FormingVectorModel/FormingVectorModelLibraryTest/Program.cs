using System;
using FormingVectorModelLibrary.Core.IO;
using FormingVectorModelLibrary.Core.Objects.Visual;
using FormingVectorModelLibrary.Core.Transformation;

namespace FormingVectorModelLibraryTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("reading");
            IImage image = Reader.Read(@"..\..\..\..\..\data\2.png");

            int i = 1;

            Transform(image, new YiqGrayscalation(), @"..\..\..\..\..\data\2_out_" + i++ + ".png");
            Transform(image, new Invertation(), @"..\..\..\..\..\data\2_out_" + i++ + ".png");
            //Transform(image, new MiddleThresholdBinarization(), @"..\..\..\..\..\data\2_out_" + i++ + ".png");
            Transform(image, new OtsuBinarization(), @"..\..\..\..\..\data\2_out_" + i++ + ".png");
            Transform(image, new NoiseRemover(), @"..\..\..\..\..\data\2_out_" + i++ + ".png");

        }

        static void Transform(IImage image, ITransformation transformation, string savePath)
        {
            Console.Write(transformation.GetType().Name + " ");
            image.Transform(transformation);

            Console.WriteLine("writing");
            Writer.Write(image, savePath);
        }
    }
}
