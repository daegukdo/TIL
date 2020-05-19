using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    // define delegate
    delegate int Compare<T>(T a, T b);

    class Program
    {
        static void Main(string[] args)
        {

            int[] array1 = { 3, 7, 4, 2, 10};

            Console.WriteLine("Sorting ascending...");
            BubbleSort<int>(array1, new Compare<int>(AscendCompare));
            for (int i = 0; i < array1.Length; i++)
                Console.Write("{0} ", array1[i]);
            Console.WriteLine("\n");


            string[] array2 = { "abc", "def", "ghi", "jkl", "mno" };

            Console.WriteLine("Sorting descending...");
            BubbleSort<string>(array2, new Compare<string>(DescendCompare));
            for (int i = 0; i < array2.Length; i++)
                Console.Write("{0} ", array2[i]);
            Console.WriteLine("\n");


            return;
        }

        static int AscendCompare<T>(T a, T b) where T : IComparable<T>
        {
            return a.CompareTo(b);
        }

        static int DescendCompare<T>(T a, T b) where T : IComparable<T>
        {
            return a.CompareTo(b) * -1;
        }

        static void BubbleSort<T>(T[] DataSet, Compare<T> Comparer)
        {
            int i = 0;
            int j = 0;
            T temp;

            for (i = 0; i < DataSet.Length - 1; i++)
            {
                for (j = 0; j < DataSet.Length - (i + 1); j++)
                {
                    if (Comparer(DataSet[j], DataSet[j + 1]) > 0)
                    {
                        temp = DataSet[j + 1];
                        DataSet[j + 1] = DataSet[j];
                        DataSet[j] = temp;
                    }
                }
            }
        }
    }

    
}
