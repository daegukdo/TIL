using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace threadPoolTest
{
    class Program
    {
        static WriteLog writeLog = null;

        static void Main(string[] args)
        {
            writeLog = new WriteLog();
            
            writeLog.WritePath = "test1.txt";
            SetLogData1();

            Thread thread = new Thread(writeLog.Write);
            thread.Start(); // writeLog.Write();

            writeLog.WritePath = "test2.txt";
            SetLogData2();
            writeLog.Write();
        }

        static void SetLogData1()
        {
            if (writeLog == null)
            {
                return;
            }

            int numOfRand = 1000000;
            Random rand = new Random();
            int randNum = 0;

            for (int i = 0; i < numOfRand; i++)
            {
                randNum = rand.Next(numOfRand);
                writeLog.LogStrList.Add(String.Format("randNum[idx] : {0}[{1}]", randNum, i));
            }
        }

        static void SetLogData2()
        {
            if (writeLog == null)
            {
                return;
            }

            int numOfRand = 10;
            Random rand = new Random();
            int randNum = 0;

            for (int i = 0; i < numOfRand; i++)
            {
                randNum = rand.Next(numOfRand);
                writeLog.LogStrList.Add(String.Format("randNum[idx] : {0}[{1}]", randNum, i));
            }
        }
    }
}
