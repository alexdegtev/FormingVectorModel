using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class MiddleThresholdBinarization : ABinarization
    {
        protected override byte GetTreshold(IImage image)
        {
            return byte.MaxValue / 2;
        }
    }
}