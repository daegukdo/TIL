using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace test
{
    // define interface
    interface ILogger
    {
        // if something inherit this interface, that need to define this function
        void WriteLog(string message);
    }

    // inherit from interface ILogger
    class ConsoleLogger : ILogger
    {
        // need to define this function in interface ILogger
        public void WriteLog(string message)
        {
            Console.WriteLine("{0} {1}", DateTime.Now.ToLocalTime(), message);
        }
    }

    // inherit from interface ILogger
    class FileLogger : ILogger
    {
        private StreamWriter writer;

        public FileLogger(string path)
        {
            writer = File.CreateText(path);
            writer.AutoFlush = true;
        }

        // need to define this function in interface ILogger
        public void WriteLog(string message)
        {
            writer.WriteLine("{0} {1}", DateTime.Now.ToLocalTime(), message);
        }
    }

    class ClimateMonitor
    {
        private ILogger logger;
        public ClimateMonitor(ILogger logger)
        {
            this.logger = logger;
        }

        public void start()
        {
            while (true)
            {
                Console.Write("enter the temp. : ");
                string temperature = Console.ReadLine();
                if (temperature == "")
                    break;
                logger.WriteLog("this temp. : " + temperature);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ClimateMonitor monitor = new ClimateMonitor(new FileLogger("MyLog.txt"));
            monitor.start();

            return;
        }
    }
}
