using Emgu.CV;
using Emgu.CV.CvEnum;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class GuoHallSkeletization : ISkeletization
    {
        public void Execute(Objects.Visual.IImage image)
        {
            Mat skeleton = new Mat(image.Rows, image.Cols, DepthType.Cv8U, 1);


        }
    }
}