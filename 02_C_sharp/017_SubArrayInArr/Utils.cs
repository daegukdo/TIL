using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    public static class Utils
    {
        public static T[] SubArray<T>(this T[] data, int startIdx, int endIdx)
        {
            int length = endIdx - startIdx + 1;

            T[] result = new T[length];
            Array.Copy(data, startIdx, result, 0, length);
            return result;
        }
    }
}
