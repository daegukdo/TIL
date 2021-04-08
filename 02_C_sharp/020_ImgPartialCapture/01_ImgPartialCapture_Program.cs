using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Drawing;
using System.Drawing.Imaging;

namespace ImgCaptureTest
{
    class Program
    {
        static void Main(string[] args)
        {
            string pngFilePath = "aaa.png";

            ImgCapture imgCapture = new ImgCapture(200, 200, 400, 400);
            imgCapture.SetPath(pngFilePath);
            imgCapture.DoCaptureImage();

            return;
        }
    }

    public class ImgCapture
    {
        private int _refX = 0;
        private int _refY = 0;
        private int _imgW = 0;
        private int _imgH = 0;

        private string filePath = null;

        public ImgCapture(int refX = 0, int refY = 0, int imgW = 0, int imgH = 0)
        {
            _refX = refX;
            _refY = refY;
            _imgW = imgW;
            _imgH = imgH;
        }

        public void SetPath(string path)
        {
            filePath = path;
        }

        public void DoCaptureImage()
        {
            if (filePath != null)
            {
                if (_imgW == 0 || _imgH == 0)
                    return;

                using (System.Drawing.Bitmap bitmap = new System.Drawing.Bitmap((int)_imgW, (int)_imgH))
                {
                    using (System.Drawing.Graphics g = System.Drawing.Graphics.FromImage(bitmap))
                    {
                        g.CopyFromScreen(_refX, _refY, 0, 0, bitmap.Size);
                    }

                    bitmap.Save(filePath, ImageFormat.Png);
                }
            }
        }
    }
}
