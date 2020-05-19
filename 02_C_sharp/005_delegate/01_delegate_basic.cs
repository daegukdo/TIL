using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    // define delegate
    delegate int MyDelegate(int a, int b);

    class Program
    {
        static void Main(string[] args)
        {
            Calculator Calc = new Calculator();
            MyDelegate CallBack;

            // use delegate (function has same form like defined delegate)
            CallBack = new MyDelegate(Calc.Plus);
            Console.WriteLine(CallBack(3, 4));

            // use delegate (function has same form like defined delegate)
            CallBack = new MyDelegate(Calc.Minus);
            Console.WriteLine(CallBack(4, 3));

            return;
        }
    }

    class Calculator
    {
        public int Plus(int a, int b)
        {
            return a + b;
        }

        public int Minus(int a, int b)
        {
            return a - b;
        }
    }
}
