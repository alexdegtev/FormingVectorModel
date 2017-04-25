using System;
using System.Collections.Generic;
using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class NoiseRemover : INoiseRemover
    {
        public void Execute(IImage image)
        {
            for (int i = 1; i < image.Rows - 1; i++)
            {
                for (int j = 1; j < image.Cols - 1; j++)
                {
                    IColor currentColor = image[i, j];
                    if (currentColor.Brightness == (byte) Color.BinaryColor.TurnOff)
                    {
                        IList<IColor> neighbours = image.GetNeighboursByBrightness(i, j, (byte) Color.BinaryColor.TurnOn);
                        if (neighbours.Count >= 5)
                        {
                            image[i, j].Brightness = (byte) Color.BinaryColor.TurnOn;
                        }
                    }
                    else
                    {
                        IList<IColor> neighbours = image.GetNeighboursByBrightness(i, j, (byte)Color.BinaryColor.TurnOff);
                        if (neighbours.Count == 5)
                        {
                            image[i, j].Brightness = (byte)Color.BinaryColor.TurnOff;
                        }
                    }
                }
            }
        }
    }
}