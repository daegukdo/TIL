using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// DotNetZip can install using Nuget package
// need to refer DotNetZip for loading (please refer DotNetZip.dll)
using Ionic.Zip;

namespace zipExtChangeNExtractWithPW
{
    class Program
    {
        static void Main(string[] args)
        {
            string crxFile = "00_testData\\data.abc";
            string zipFile = "01_testResult\\data.zip";

            // copy some data to another directory
            // and change file extension using string variable
            CopyNChangeFileToDir(crxFile, zipFile);

            string targetDirectory = "01_testResult\\";

            // load password for extracting zip
            // extract zip file
            using (ZipFile zip = ZipFile.Read(zipFile))
            {
                zip.Password = "zip";
                zip.ExtractAll(targetDirectory, Ionic.Zip.ExtractExistingFileAction.DoNotOverwrite);
            }

            Console.WriteLine("Zip file has been successfully extracted.");
            Console.Read();
        }

        private static void CopyNChangeFileToDir(string sourceFileName, string targetFileName)
        {
            System.IO.File.Copy(sourceFileName, targetFileName, true);
        }
    }
}
