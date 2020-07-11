using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Dicom;
using Dicom.Imaging;
using System.Drawing;
using System.IO;
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

        public bool ImportImage(string imageFile, string newFilePah, string oldDicomFile)
        {
            Bitmap bitmap = new Bitmap(imageFile);
            int rows, columns;
            byte[] pixels = GetPixels(bitmap, out rows, out columns);
            MemoryByteBuffer buffer = new MemoryByteBuffer(pixels);
            DicomDataset dataset = new DicomDataset();
            var dicomfile = DicomFile.Open(oldDicomFile);
            dataset = dicomfile.Dataset.Clone();

            dataset.AddOrUpdate(DicomTag.PhotometricInterpretation, PhotometricInterpretation.Rgb.Value);
            dataset.AddOrUpdate(DicomTag.Rows, (ushort)rows);
            dataset.AddOrUpdate(DicomTag.Columns, (ushort)columns);
            dataset.AddOrUpdate(DicomTag.BitsAllocated, (ushort)8);

            DicomPixelData pixelData = DicomPixelData.Create(dataset, true);
            pixelData.BitsStored = 8;
            pixelData.SamplesPerPixel = 3;
            pixelData.HighBit = 7;
            pixelData.PhotometricInterpretation = PhotometricInterpretation.Rgb;
            pixelData.PixelRepresentation = 0;
            pixelData.PlanarConfiguration = 0;
            pixelData.Height = (ushort)rows;
            pixelData.Width = (ushort)columns;
            pixelData.AddFrame(buffer);

            dicomfile = new DicomFile(dataset);
            dicomfile.Save(newFilePah);
            return true;
        }

        private byte[] GetPixels(Bitmap bitmap, out int rows, out int columns)
        {
            using (var stream = new MemoryStream())
            {
                bitmap.Save(stream, System.Drawing.Imaging.ImageFormat.Bmp);
                rows = bitmap.Height;
                columns = bitmap.Width;
                return stream.ToArray();
            }
        }

        private void _logToDebugConsole(string informationToLog)
        {
            Console.WriteLine(informationToLog);
        }
    }
}
