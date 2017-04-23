using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public interface ITransformation
    {
        void Execute(IImage image);
    }
}