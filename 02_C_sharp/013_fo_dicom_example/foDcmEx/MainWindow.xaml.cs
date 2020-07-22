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
using System.IO;

using foDcmEx.Models;

namespace foDcmEx
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        // ref : https://github.com/fo-dicom/fo-dicom
        // ref : https://fo-dicom.github.io/html/632e5303-a1e0-492f-8f6a-8b78e9037c40.htm#!

        public MainWindow()
        {
            InitializeComponent();

            _checkDCMHeader();
        }

        private void _checkDCMHeader()
        {
            DCMData dcmHeader = new DCMData("data/0002.dcm");

            dcmHeader.ShowDcmHeaderToConsole();

            dcmHeader.ShowDcmImage();
        }
    }
}
