using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public abstract class ABinarization : IBinarization
    {
        public void Execute(IImage image)
        {
            byte threshold = GetTreshold(image);

            foreach (IColor color in image)
            {
                color.Brightness = color.Brightness > threshold
                    ? (byte) Color.BinaryColor.TurnOn
                    : (byte) Color.BinaryColor.TurnOff;
            }
        }

        protected abstract byte GetTreshold(IImage image);
    }
}