using System;
using System.Collections.Generic;
using FormingVectorModelLibrary.Core.Objects.Visual;

namespace FormingVectorModelLibrary.Core.Transformation
{
    public class OtsuBinarization : ABinarization
    {
        private IImage image;

        protected override byte GetTreshold(IImage image)
        {
            this.image = image;
            int min, max;
            IList<int> histogram = GetHistogram(out min, out max);

            int tmp1 = 0, tmp2 = 0;
            for (int i = 0; i <= max - min; i++)
            {
                tmp1 += i * histogram[i];
                tmp2 += histogram[i];
            }

            int alpha = 0, beta = 0, threshold = 0;
            double w1, a, sigma, sigmaMax = -1;
            for (int i = 0; i < max - min; i++)
            {
                alpha += i * histogram[i];
                beta += histogram[i];

                w1 = (double) beta / tmp2;
                a = (double) alpha / beta - (double) (tmp1 - alpha) / (tmp2 - beta);
                sigma = w1 * (1 - w1) * a * a;

                if (sigma > sigmaMax)
                {
                    sigmaMax = sigma;
                    threshold = i;
                }
            }

            return (byte)(threshold + min);
        }

        private IList<int> GetHistogram(out int min, out int max)
        {
            min = Int32.MaxValue;
            max = Int32.MinValue;
            int tmp;
            foreach (IColor color in image)
            {
                tmp = color.Brightness;
                if (tmp < min) min = tmp;
                if (tmp > max) max = tmp;
            }

            IList<int> histogram = new List<int>();
            int histgramSize = max - min + 1;
            for (int i = 0; i < histgramSize; i++)
            {
                histogram.Add(0);
            }

            foreach (IColor color in image)
            {
                histogram[color.Brightness - min]++;
            }

            return histogram;
        }
    }
}