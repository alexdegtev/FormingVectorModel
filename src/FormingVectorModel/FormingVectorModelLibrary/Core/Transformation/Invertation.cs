using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class Invertation : IInvertation
    {
        public void Execute(IImage image)
        {
            foreach (IColor color in image)
            {
                color.Red = (byte)(byte.MaxValue - color.Red);
                color.Green = (byte)(byte.MaxValue - color.Green);
                color.Blue = (byte)(byte.MaxValue - color.Blue);
            }
        }
    }
}