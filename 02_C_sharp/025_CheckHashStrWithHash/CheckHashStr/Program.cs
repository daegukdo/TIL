using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckHashStr
{
    class Program
    {
        static void Main(string[] args)
        {
            string filePath = "checkHashTestText.txt";

            // write file with checkHash
            _writeFileWithCheckHash(filePath);

            // checkHash
            bool isCorrect = _checkHash(filePath);

            if (isCorrect)
            {
                Console.WriteLine("file is good");
            }
            else
            {
                Console.WriteLine("file txt have issue; not correct checkHash");
            }

            return;
        }

        static void _writeFileWithCheckHash(string filePath)
        {
            // str data
            string strData = "doDotLog is good!\nYes!";

            // make checkHash
            string checkHashStr = "";
            using (System.Security.Cryptography.MD5 md5 = System.Security.Cryptography.MD5.Create())
            {
                checkHashStr = BitConverter.ToString(md5.ComputeHash(System.Text.Encoding.UTF8.GetBytes(strData))).Replace("-", String.Empty);
                strData = checkHashStr + '\n' + strData;
            }

            using (System.IO.StreamWriter writer = new System.IO.StreamWriter(filePath))
            {
                writer.WriteLine(strData);
                writer.Close();
            }
        }

        static bool _checkHash(string filePath)
        {
            // read file
            string[] readRawLines = System.IO.File.ReadAllLines(filePath);
            string[] readLines = new string[readRawLines.Length - 1];

            // check hash
            string checkHashStrAns = readRawLines[0];
            Array.Copy(readRawLines, 1, readLines, 0, readRawLines.Length - 1);
            string stmRcvDataStr = string.Join("\n", readLines);
            string checkHashStr = "";

            using (System.Security.Cryptography.MD5 md5 = System.Security.Cryptography.MD5.Create())
            {
                checkHashStr = BitConverter.ToString(md5.ComputeHash(System.Text.Encoding.UTF8.GetBytes(stmRcvDataStr))).Replace("-", String.Empty);
            }

            if (checkHashStr != checkHashStrAns)
            {
                return false;
            }

            return true;
        }
    }
}
