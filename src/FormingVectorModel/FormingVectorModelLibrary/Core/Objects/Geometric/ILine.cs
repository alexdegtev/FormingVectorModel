namespace FormingVectorModelLibrary.Core.Objects.Geometric
{
    public interface ILine : IObject
    {
        IPoint Begin { get; }
        IPoint End { get; }
    }
}