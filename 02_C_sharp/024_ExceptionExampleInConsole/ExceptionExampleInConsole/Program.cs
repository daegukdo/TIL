using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExceptionExampleInConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // run func.
            bool rst = _exFunc();

            // check bool
            if (rst)
            {
                Console.WriteLine("true");
            }

            return;
        }

        static bool _exFunc()
        {
            try
            {
                // normal : "file.txt"
                // exception : "_file.txt"
                string filePath = "_file.txt";
                string[] readLines = System.IO.File.ReadAllLines(filePath);
                string value = readLines[0];

                if (value == "value")
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(String.Format("[{0}] exception info. : {1}", DateTime.Now.ToString("HH:mm:ss.fff"), ex.ToString()));
                return false;
            }
        }
    }
}
