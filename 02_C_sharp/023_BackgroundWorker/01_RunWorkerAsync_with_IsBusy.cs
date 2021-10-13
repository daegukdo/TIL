using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    using System;
    using System.ComponentModel;
    class Program
    {
        static void Main(string[] args)
        {
            BackgroundWorkerTest bwt = new BackgroundWorkerTest();

            while(true)
            {
                bwt.Execute();
            }

            return;
        }
    }

    class BackgroundWorkerTest
    {
        private BackgroundWorker worker;

        public BackgroundWorkerTest()
        {
            worker = new BackgroundWorker();
            worker.DoWork += new DoWorkEventHandler(worker_DoWork);
        }
        ~BackgroundWorkerTest()
        {
            worker.DoWork -= new DoWorkEventHandler(worker_DoWork);
        }

        public void Execute()
        {
            Console.WriteLine("Execute");

            // InvalidOperationException 방지
            while (worker.IsBusy) { }
            // 쓰레드풀에서 작업쓰레드 시작
            worker.RunWorkerAsync();
        }

        // 작업쓰레드가 실행할 Task 메서드
        void worker_DoWork(object sender, DoWorkEventArgs e)
        {
            //긴 처리 가정
            Console.WriteLine("Long running task");
        }
    }
}
