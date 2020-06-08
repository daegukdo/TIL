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
using System.Windows.Threading;
using System.ComponentModel;

namespace WpfUIThread
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public class CheckProcessFlag : INotifyPropertyChanged
        {
            public event PropertyChangedEventHandler PropertyChanged;

            private void NotifyPropertyChanged()
            {
                if (PropertyChanged != null)
                {
                    PropertyChanged(this, new PropertyChangedEventArgs("fin"));
                }
            }

            public bool SetProcessTgFlag
            {
                get { return ProcessTgFlag; }
                set
                {
                    ProcessTgFlag = value;

                    NotifyPropertyChanged();
                }
            }

            private bool ProcessTgFlag = false;
        }

        CheckProcessFlag checkProcessFlag;
        BackgroundWorker threadProcess = new BackgroundWorker();

        public MainWindow()
        {
            InitializeComponent();

            checkProcessFlag = new CheckProcessFlag();
            checkProcessFlag.SetProcessTgFlag = false;
            checkProcessFlag.PropertyChanged += new PropertyChangedEventHandler(processFin);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            long a = 0;
            bool grap = true;

            while (grap)
            {
                a = a + 1;

                if (a > 300000000)
                {
                    grap = false;
                }
            }

            if (checkProcessFlag.SetProcessTgFlag == true)
            {
                checkProcessFlag.SetProcessTgFlag = false;
            }
            else
            {
                checkProcessFlag.SetProcessTgFlag = true;
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            threadProcess.DoWork += new DoWorkEventHandler(testWhileWithSync);
            threadProcess.WorkerSupportsCancellation = false;
            threadProcess.RunWorkerAsync();
        }

        private void testWhileWithSync(object sender, DoWorkEventArgs e)
        {
            long a = 0;
            bool grap = true;

            while (grap)
            {
                a = a + 1;

                if (a > 300000000)
                {
                    grap = false;
                }
            }

            if (checkProcessFlag.SetProcessTgFlag == true)
            {
                checkProcessFlag.SetProcessTgFlag = false;
            }
            else
            {
                checkProcessFlag.SetProcessTgFlag = true;
            }
        }

        private void processFin(object sender, PropertyChangedEventArgs e)
        {
            Dispatcher.Invoke(DispatcherPriority.Normal, new Action(delegate
            {
                if (heartToggle.IsChecked == true)
                {
                    heartToggle.IsChecked = false;
                }
                else
                {
                    heartToggle.IsChecked = true;
                }

                if (smileToggle.IsChecked == true)
                {
                    smileToggle.IsChecked = false;
                }
                else
                {
                    smileToggle.IsChecked = true;
                }
            }));

            threadProcess.DoWork -= new DoWorkEventHandler(testWhileWithSync);
        }
    }
}
