using System;
using System.Collections.Generic;
using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class NoiseRemover : INoiseRemover
    {
        private byte middleColor = Byte.MaxValue / 2;

        public void Execute(IImage image)
        {
            for (int i = 1; i < image.Rows - 1; i++)
            {
                for (int j = 1; j < image.Cols - 1; j++)
                {
                    IColor currentColor = image[i, j];
                    if (currentColor.Brightness == (byte) Color.BinaryColor.TurnOff)
                    {
                        //IList<IColor> neighbours = image.
                    }
                }
            }
        }

        private byte GetDominantColor(IList<IColor> colors)
        {
            int turnOnCount = 0, turnOffCount = 0;

            foreach (var color in colors)
            {
                if (color.Brightness == (byte) Color.BinaryColor.TurnOn)
                {
                    turnOnCount++;
                }
                else
                {
                    turnOffCount++;
                }
            }

            if (turnOnCount > turnOffCount) return (byte) Color.BinaryColor.TurnOn;
            if (turnOnCount < turnOffCount) return (byte) Color.BinaryColor.TurnOff;
            return middleColor;
        }
    }
}