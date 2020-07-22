using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Diagnostics;
using System.Drawing;
using System.IO;
using Dicom;
using Dicom.Imaging;
using Dicom.IO.Buffer;

namespace foDcmEx.Models
{
    class DCMData
    {
        private DicomFile _dcmFile = null;
        private DicomDataset _dcmDataset = null;
        private DicomImage _dcmImg = null;
        private Dictionary<string, string> _dcmHeaderDict = null;

        public DCMData(string pathToDicomTestFile)
        {
            _loadDcmData(pathToDicomTestFile);
            _loadDcmHeader();
        }

        private void _loadDcmData(string pathToDicomTestFile)
        {
            try
            {
                var tmpStr = "";
                tmpStr = string.Format("Attempting to extract information from DICOM file:{0}...", pathToDicomTestFile);

                _logToDebugConsole(tmpStr);

                _dcmFile = DicomFile.Open(pathToDicomTestFile);
                _dcmDataset = _dcmFile.Dataset;
                _dcmImg = new DicomImage(_dcmDataset);
            }
            catch (Exception e)
            {
                _logToDebugConsole("Error occured during DICOM file dump operation -> {e.StackTrace}");
            }
        }

        private void _loadDcmHeader()
        {
            if (_dcmFile == null || _dcmDataset == null || _dcmImg == null) { _logToDebugConsole("please load your dcm data"); return; }

            foreach (var tag in _dcmDataset)
            {
                _dcmHeaderDict.Add(tag.ToString(), _dcmDataset.GetValueOrDefault(tag.Tag, 0, ""));
            }
        }

        public void ShowDcmHeaderToConsole()
        {
            if (_dcmHeaderDict == null) { _logToDebugConsole("please load your dcm data"); return; }

            var tmpStr = "";

            foreach (var tagSet in _dcmHeaderDict)
            {
                tmpStr = string.Format(" {0} : {1}", tagSet.Key, tagSet.Value);
                _logToDebugConsole(tmpStr);
            }

            _logToDebugConsole("Extract operation from DICOM file successful");
        }

        public void ShowDcmImage()
        {
            if (_dcmFile == null || _dcmDataset == null || _dcmImg == null) { _logToDebugConsole("please load your dcm data"); return; }

            var dcmImg = _dcmImg.RenderImage();

            var dcmImgArr = dcmImg.Pixels;

            var dcmImgArrData = dcmImgArr.Data;


        }

        private void _logToDebugConsole(string informationToLog)
        {
            Console.WriteLine(informationToLog);
        }
    }
}
