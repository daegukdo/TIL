using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    // define delegate
    delegate void EventHandler(string message);

    // define delegate instance
    class MyNotifier
    {
        // use same delegate above
        public event EventHandler SomethingHappend;
        public void DoSomething(int number)
        {
            int temp = number % 10;

            if (temp != 0 && temp % 3 == 0)
            {
                // occur event as number is 3 or 6 or 9
                SomethingHappend(String.Format("{0} : clap!", number));
            }
        }
    }

    class Program
    {
        // define event handler that is same as delegate format
        static public void MyHandler(string message)
        {
            Console.WriteLine(message);
        }

        static void Main(string[] args)
        {
            // define instance and register event handler
            MyNotifier notifier = new MyNotifier();
            notifier.SomethingHappend += new EventHandler(MyHandler);

            for (int i = 1; i < 30; i++)
            {
                // call event handler
                notifier.DoSomething(i);
            }

                return;
        }
    }
}
