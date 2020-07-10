using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Dicom;
using Dicom.Imaging;

namespace foDcmEx.Models
{
    class DCMHeader
    {
        private DicomFile _dcmFile = null;
        private DicomDataset _dcmDataset = null;
        private DicomImage _dcmImg = null;

        public DCMHeader(string pathToDicomTestFile)
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

        public void ShowDcmHeaderToConsole()
        {
            if (_dcmFile == null || _dcmDataset == null || _dcmImg == null) { _logToDebugConsole("please load your dcm data"); return; }

            var tmpStr = "";

            foreach (var tag in _dcmDataset)
            {
                tmpStr = string.Format(" {0} : {1}", tag, _dcmDataset.GetValueOrDefault(tag.Tag, 0, ""));
                _logToDebugConsole(tmpStr);
            }

            _logToDebugConsole("Extract operation from DICOM file successful");
        }

        private void _logToDebugConsole(string informationToLog)
        {
            Console.WriteLine(informationToLog);
        }
    }
}
