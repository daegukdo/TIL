using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            string strsWithComma = "1,2,3,4,5,6,4,4,2,2,1,1";

            double[] dbArr = Array.ConvertAll(strsWithComma.Split(','), Double.Parse);

            foreach (var elm in dbArr)
            {
                Console.WriteLine(elm);
                Console.WriteLine(elm.GetType());
            }
        }
    }
}

// ref
// https://stackoverflow.com/questions/9524682/fastest-way-to-convert-string-array-to-double-array
// https://docs.microsoft.com/ko-kr/dotnet/api/system.array.convertall?view=net-5.0
