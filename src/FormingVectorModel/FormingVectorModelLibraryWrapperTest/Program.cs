using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using FormingVectorModelLibraryWrapper;

namespace FormingVectorModelLibraryWrapperTest
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 10;
            FormingVectorModelLibraryWrapper.MyObjects.Array a = new FormingVectorModelLibraryWrapper.MyObjects.Array(n);
            Console.WriteLine(a.get(5));
            a.set(5, 5);
            Console.WriteLine(a.get(5));
        }
    }
}
