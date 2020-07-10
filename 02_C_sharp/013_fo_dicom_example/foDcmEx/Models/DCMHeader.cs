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
        public void ShowDcmHeader(string pathToDicomTestFile)
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
                    tmpStr = string.Format(" {0} : {1}", tag, dicomDataset.GetValueOrDefault(tag.Tag, 0, ""));
                    LogToDebugConsole(tmpStr);
                }

                LogToDebugConsole("Extract operation from DICOM file successful");
            }
            catch (Exception e)
            {
                LogToDebugConsole("Error occured during DICOM file dump operation -> {e.StackTrace}");
            }
        }

        public void LogToDebugConsole(string informationToLog)
        {
            Console.WriteLine(informationToLog);
        }
    }
}
