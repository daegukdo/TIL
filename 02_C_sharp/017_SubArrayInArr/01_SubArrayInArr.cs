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
            _testCode();
            _testCodeWithFunc();
        }

        private static void _testCode()
        {
            // test code
            int[] sourceArrInt = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int startIdx = 3;
            int endIdx = 7;
            int length = endIdx - startIdx + 1;

            int[] targetArrInt = new int[length];

            Array.Copy(sourceArrInt, startIdx, targetArrInt, 0, length);

            foreach (var elm in targetArrInt)
            {
                Console.WriteLine(elm);
            }
        }

        private static void _testCodeWithFunc()
        {
            // test with func.
            int[] sourceArrInt = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int startIdx = 3;
            int endIdx = 7;

            int[] targetArrInt = Utils.SubArray(sourceArrInt, startIdx, endIdx);

            foreach (var elm in targetArrInt)
            {
                Console.WriteLine(elm);
            }
        }
    }
}

// ref
// https://stackoverflow.com/questions/943635/how-do-i-clone-a-range-of-array-elements-to-a-new-array
// https://docs.microsoft.com/ko-kr/dotnet/api/system.array.copy?view=net-5.0
