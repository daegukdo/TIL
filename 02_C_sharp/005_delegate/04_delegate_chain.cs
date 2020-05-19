using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    // define delegate
    delegate void Notify(string message);

    class Notifier
    {
        public Notify EventOccured;
    }

    class EventListener
    {
        private string name;
        public EventListener(string name)
        {
            this.name = name;
        }

        public void SomethingHappend(string message)
        {
            Console.WriteLine("{0}.SomethingHappend : {1}", name, message);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Notifier notifier = new Notifier();

            EventListener listener1 = new EventListener("Listener1");
            EventListener listener2 = new EventListener("Listener2");
            EventListener listener3 = new EventListener("Listener3");

            // use += operator for adding delegate chain
            notifier.EventOccured += listener1.SomethingHappend;
            notifier.EventOccured += listener2.SomethingHappend;
            notifier.EventOccured += listener3.SomethingHappend;
            notifier.EventOccured("You've got mail.");

            Console.WriteLine();

            // use -= operator for removing delegate chain
            notifier.EventOccured -= listener2.SomethingHappend;
            notifier.EventOccured("Download complete.");

            Console.WriteLine();

            // use +, = operator for making delegate chain
            notifier.EventOccured = new Notify(listener2.SomethingHappend) + new Notify(listener3.SomethingHappend);
            notifier.EventOccured("New product");

            Console.WriteLine();

            // use Delegate.Combine() method for making delegate chain
            Notify notify1 = new Notify(listener1.SomethingHappend);
            Notify notify2 = new Notify(listener2.SomethingHappend);

            notifier.EventOccured = (Notify)Delegate.Combine(notify1, notify2);
            notifier.EventOccured("fire");

            Console.WriteLine();

            // use Delegate.Remove() method for removing delegate chain
            notifier.EventOccured = (Notify)Delegate.Remove(notifier.EventOccured, notify2);
            notifier.EventOccured("get it");

            return;
        }
    }

    
}
