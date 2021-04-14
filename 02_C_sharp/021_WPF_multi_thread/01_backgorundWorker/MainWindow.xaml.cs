using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.ComponentModel;
using System.Threading;
using System.Windows.Threading;
namespace WpfBackGround
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private BackgroundWorker myBackgroundWorkerThread;
        private int number = 0;

        public MainWindow()
        {
            InitializeComponent();

            initBackgroundThread();
        }

        private void initBackgroundThread()
        {
            myBackgroundWorkerThread = new BackgroundWorker();
            myBackgroundWorkerThread.DoWork += doWork;
            myBackgroundWorkerThread.RunWorkerAsync();
        }

        private void btn_Click(object sender, RoutedEventArgs e)
        {
            txtLbl.Content = number.ToString();
        }

        private void doWork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                Thread.Sleep(200);

                this.Dispatcher.BeginInvoke(DispatcherPriority.Normal,
                    (ThreadStart)delegate()
                    {
                        txtBackLbl.Content = number.ToString();

                        number++;
                        if (number % 10000 == 0)
                        {
                        number = 0;
                        }
                    });
            }
        }
    }
}
