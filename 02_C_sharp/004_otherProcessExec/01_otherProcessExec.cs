using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace otherProcessExec
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                using (System.Diagnostics.Process dialogProcess = new System.Diagnostics.Process())
                {
                    dialogProcess.StartInfo.FileName = ".\\resource\\dialog.exe";

                    dialogProcess.Start();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
