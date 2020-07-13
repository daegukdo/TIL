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

namespace EventBasedMVVMwithControl.UIComponents
{
    /// <summary>
    /// ActionButton.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ActionButton : UserControl
    {
        public ActionButton()
        {
            InitializeComponent();
        }

        public string ActionBtnTextStr
        {
            get { return (string)GetValue(ActionBtnTextStrProperty); }
            set { SetValue(ActionBtnTextStrProperty, value); }
        }
        public static readonly DependencyProperty ActionBtnTextStrProperty =
            DependencyProperty.Register("ActionBtnTextStr", typeof(string), typeof(ActionButton), new UIPropertyMetadata(""));

        public event RoutedEventHandler Click;

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Click(this, e);
        }
    }
}
