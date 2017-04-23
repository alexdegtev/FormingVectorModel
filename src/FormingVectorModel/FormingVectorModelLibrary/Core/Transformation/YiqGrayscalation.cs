using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class YiqGrayscalation : IGrayscalation
    {
        public void Execute(IImage image)
        {
            foreach (IColor color in image)
            {
                color.Brightness = color.Brightness;
            }
        }
    }
}