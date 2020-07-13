﻿using System;
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

using EventBasedMVVMwithControl.Controls;

namespace EventBasedMVVMwithControl
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        private EventHandler _callStrData = null;
        private string _strData = "";

        public MainWindow()
        {
            InitializeComponent();
            _initText();
        }

        private void _initText()
        {
            mainLbl.MainTextLblStr = "main";
            subLbl.SubTextLblStr = "sub";

            btn1.ActionBtnTextStr = "btn1";
            btn2.ActionBtnTextStr = "btn2";
            btn3.ActionBtnTextStr = "btn3";
        }

        private void _init()
        {
            StringDataControl strCtrl = new StringDataControl();
            _callStrData += strCtrl.DoActionStrData;
            strCtrl.SendStrData += _rcvStrData;
        }

        private void _callActA()
        {
            if (_callStrData != null) { _callStrData("A", null); }
        }

        private void _rcvStrData(object sender, EventArgs e)
        {
            string tmpStr = sender as string;
            _strData = tmpStr;
        }

        private void btn1_click(object sender, RoutedEventArgs e)
        {
            _init();
            _callActA();
        }

        private void btn2_click(object sender, RoutedEventArgs e)
        {
            mainLbl.MainTextLblStr = _strData;
        }
    }
}
