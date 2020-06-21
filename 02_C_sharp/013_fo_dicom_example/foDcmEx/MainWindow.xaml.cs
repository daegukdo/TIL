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
using System.IO;

using Dicom;
using Dicom.Imaging;

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
            showDcmHeader("data/0002.dcm");
        }

        private void showDcmHeader(string pathToDicomTestFile)
        {
            try
            {
                var tmpStr = "";
                tmpStr = string.Format("Attempting to extract information from DICOM file:{0}...", pathToDicomTestFile);

                LogToDebugConsole(tmpStr);

                var dcmFile = DicomFile.Open(pathToDicomTestFile);
                var dicomDataset = dcmFile.Dataset;

                var dcmImage = new DicomImage(dicomDataset);
                    
                foreach (var tag in dicomDataset)
                {
                    tmpStr = string.Format(" {0} : {1}", tag, dicomDataset.GetValueOrDefault(tag.Tag, 0, "") );
                    LogToDebugConsole(tmpStr);
                }

                LogToDebugConsole("Extract operation from DICOM file successful");
            }
            catch (Exception e)
            {
                LogToDebugConsole("Error occured during DICOM file dump operation -> {e.StackTrace}");
            }
        }

        private void LogToDebugConsole(string informationToLog)
        {
            Console.WriteLine(informationToLog);
        }
    }
}