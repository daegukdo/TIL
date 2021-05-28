using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;

namespace threadPoolTest
{
    public class WriteLog
    {
        public string WritePath = "";
        public List<string> LogStrList = null;

        public WriteLog()
        {
            LogStrList = new List<string>();
        }

        public void Write()
        {
            ThreadPool.QueueUserWorkItem(write);

            /*
            if (WritePath == "" || LogStrList == null)
            {
                return;
            }

            using (StreamWriter writer = new StreamWriter(WritePath))
            {
                foreach (var line in LogStrList)
                {
                    writer.WriteLine(line);
                }

                LogStrList = new List<string>();
            }
            */
        }

        private void write(object obj)
        {
            if (WritePath == "" || LogStrList == null)
            {
                return;
            }

            using (StreamWriter writer = new StreamWriter(WritePath))
            {
                foreach (var line in LogStrList)
                {
                    writer.WriteLine(line);
                }

                LogStrList = new List<string>();
            }
        }
    }
}
