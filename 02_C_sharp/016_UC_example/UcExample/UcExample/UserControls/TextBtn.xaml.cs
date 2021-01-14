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

namespace UcExample.UserControls
{
    /// <summary>
    /// TextBtn.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TextBtn : UserControl
    {
        public TextBtn()
        {
            InitializeComponent();
        }

        public string BtnTextStr
        {
            get { return (string)GetValue(BtnTextStrProperty); }
            set { SetValue(BtnTextStrProperty, value); }
        }
        public static readonly DependencyProperty BtnTextStrProperty =
            DependencyProperty.Register("BtnTextStr", typeof(string), typeof(TextBtn), new UIPropertyMetadata("default"));

        public event RoutedEventHandler Click;

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Click(this, e);
        }
    }
}
