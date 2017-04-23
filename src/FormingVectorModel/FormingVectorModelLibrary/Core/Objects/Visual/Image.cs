using System.Collections;
using System.Collections.Generic;
using FormingVectorModelLibrary.Core.Objects.Mathematic;
using FormingVectorModelLibrary.Core.Transformation;

namespace FormingVectorModelLibrary.Core.Objects.Visual
{
    public class Image : IImage
    {
        private IMatrix<IColor> data;

        public Image(int rows, int cols)
        {
            data = new Matrix<IColor>(rows, cols);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="rows"></param>
        /// <param name="cols"></param>
        /// <param name="data">Array with BGR format color</param>
        public Image(int rows, int cols, byte[,,] data) : this(rows, cols)
        {
            for (int i = 0; i < Rows; i++)
            {
                for (int j = 0; j < Cols; j++)
                {
                    this.data[i, j] = new Color(data[i, j, 2], data[i, j, 1], data[i, j, 0]);
                }
            }
        }

        public Image() : this(0, 0) { }

        public int Rows => data.Rows;

        public int Cols => data.Cols;

        public IColor this[int row, int col]
        {
            get { return data[row, col]; }
            set { data[row, col] = value; }
        }

        /// <summary>
        /// Return 3d array. 1 - rows, 2 - cols, 3 - BGR values
        /// </summary>
        public byte[,,] Data
        {
            get
            {
                byte[,,] rowData = new byte[Rows, Cols, 3];

                for (int i = 0; i < Rows; i++)
                {
                    for (int j = 0; j < Cols; j++)
                    {
                        rowData[i, j, 0] = data[i, j].Blue;
                        rowData[i, j, 1] = data[i, j].Green;
                        rowData[i, j, 2] = data[i, j].Red;
                    }
                }

                return rowData;
            }
        }

        public void Transform(ITransformation transformation)
        {
            transformation.Execute(this);
        }

        public IEnumerator GetEnumerator()
        {
            return data.GetEnumerator();
        }

        public IList<IColor> GetNeighboursByBrightness(int row, int col, byte brightness)
        {
            IList<IColor> neighbours = new List<IColor>();
            for (int i = -1; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++)
                {
                    if (i == 0 && j == 0) continue;

                    
                }
            }

            return null;
        }
    }
}