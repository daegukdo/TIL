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

using MaterialDesignThemes.Wpf;

namespace UIBindingEx.UIComponents
{
    /// <summary>
    /// ToolBar.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ToolBar : UserControl
    {
        public ToolBar()
        {
            InitializeComponent();
        }

        #region properties
        public string Btn1ToolTip
        {
            get { return (string)GetValue(Btn1ToolTipProperty); }
            set { SetValue(Btn1ToolTipProperty, value); }
        }
        public static readonly DependencyProperty Btn1ToolTipProperty =
            DependencyProperty.Register("Btn1ToolTip", typeof(string), typeof(ToolBar), new UIPropertyMetadata(""));
        #endregion
    }
}
