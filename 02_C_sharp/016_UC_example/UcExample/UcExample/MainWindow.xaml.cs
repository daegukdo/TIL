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

namespace UcExample
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btn1_click(object sender, RoutedEventArgs e)
        {
            txtBtn1.BtnTextStr = "btn1, font size 20";
        }

        private void btn2_click(object sender, RoutedEventArgs e)
        {
            txtBtn2.BtnTextStr = "btn2, font size 30";
        }
    }
}
