using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Security.Cryptography;
using System.Xml;

namespace XML_RSA_Test
{
    class Program
    {
        static void Main(string[] args)
        {
            XMLRSAEncryption("xmlData\\xmlData.xml");          // xmlData --> e_xmlData
            XMLRSADecryption("xmlData\\e_xmlData.xml");        // e_xmlData --> d_e_xmlData
        }

        #region RSA encryption-decryption func.
        // use for make private and public keys
        // ref : https://icechou.tistory.com/324
        private static void makeRSAKeys(string privateKeyFilePathWithName, string publicKeyFilePathWithName)
        {
            // 암호화 개체 생성
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();

            // 개인키 생성(복호화용) ... make key for encryption
            RSAParameters privateKey = RSA.Create().ExportParameters(true);
            rsa.ImportParameters(privateKey);
            string privateKeyText = rsa.ToXmlString(true);

            StreamWriter privateKeyWriter = new StreamWriter(privateKeyFilePathWithName);
            privateKeyWriter.WriteLine(privateKeyText);
            privateKeyWriter.Close();

            // 공개키 생성(암호화용) ... make key for decryption
            RSAParameters publicKey = new RSAParameters();
            publicKey.Modulus = privateKey.Modulus;
            publicKey.Exponent = privateKey.Exponent;
            rsa.ImportParameters(publicKey);
            string publicKeyText = rsa.ToXmlString(false);

            StreamWriter publicKeyWriter = new StreamWriter(publicKeyFilePathWithName);
            publicKeyWriter.WriteLine(publicKeyText);
            publicKeyWriter.Close();
        }

        // RSA 암호화
        public static string RSAEncrypt(string getValue, string pubKey)
        {
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
            rsa.FromXmlString(pubKey);

            //암호화할 문자열을 UFT8인코딩
            byte[] inbuf = (new UTF8Encoding()).GetBytes(getValue);

            //암호화
            byte[] encbuf = rsa.Encrypt(inbuf, false);

            //암호화된 문자열 Base64인코딩
            return System.Convert.ToBase64String(encbuf);
        }

        // RSA 복호화
        public static string RSADecrypt(string getValue, string priKey)
        {
            RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
            rsa.FromXmlString(priKey);

            //sValue문자열을 바이트배열로 변환
            byte[] srcbuf = System.Convert.FromBase64String(getValue);

            //바이트배열 복호화
            byte[] decbuf = rsa.Decrypt(srcbuf, false);

            //복호화 바이트배열을 문자열로 변환
            string sDec = (new UTF8Encoding()).GetString(decbuf, 0, decbuf.Length);
            return sDec;
        }
        #endregion

        #region XML file RSA encryption-decryption func.
        private static void XMLRSAEncryption(string xmlPath)
        {
            string publicKeyText = System.IO.File.ReadAllText("keysDir\\publicKeyText1.xml");

            System.IO.StreamReader data = new System.IO.StreamReader(xmlPath);

            string line = "";

            List<string> fullLine = new List<string>();

            while ((line = data.ReadLine()) != null)
            {
                fullLine.Add(line);
            }

            data.Close();

            StreamWriter writer = new StreamWriter(Path.GetDirectoryName(xmlPath) + "\\e_" + Path.GetFileName(xmlPath), false);

            foreach (var dataLine in fullLine)
            {
                Console.WriteLine(dataLine);

                int startTag = 0;
                int endTag = 0;

                string innerText = "";
                string ecrptText = "";

                string ecrptChunk = "";
                string startChunk = "";
                string endChunk = "";

                try
                {
                    // "<> </>" 에서 '>'와 '<' 사이의 값이 tag이므로 이를 읽기 위한 방법
                    for (int i = 0; i < dataLine.Length; i++)
                    {
                        if ((dataLine[i] == '>') && (startTag == 0))
                        {
                            startTag = i + 1;
                        }

                        if ((dataLine[i] == '<') && (i > startTag) && (startTag != 0))
                        {
                            endTag = i - 1;
                        }
                    }

                    // tag 값을 변환
                    if (startTag != 0 && endTag != 0)
                    {
                        for (int i = startTag; i <= endTag; i++)
                        {
                            innerText = innerText + dataLine[i];
                        }

                        ecrptChunk = RSAEncrypt(innerText, publicKeyText);

                        startChunk = dataLine.Substring(0, startTag);

                        endChunk = dataLine.Substring(endTag+1);

                        ecrptText = startChunk + ecrptChunk + endChunk;

                        writer.WriteLine(ecrptText);
                    }
                    else
                    {
                        writer.WriteLine(dataLine);
                    }
                }
                catch
                {
                    writer.WriteLine(dataLine);
                }
            }

            writer.Close();
        }

        private static void XMLRSADecryption(string xmlPath)
        {
            string privateKeyText = System.IO.File.ReadAllText("keysDir\\privateKeyText1.xml");

            System.IO.StreamReader data = new System.IO.StreamReader(xmlPath);

            string line = "";

            List<string> fullLine = new List<string>();

            while ((line = data.ReadLine()) != null)
            {
                fullLine.Add(line);
            }

            data.Close();

            StreamWriter writer = new StreamWriter(Path.GetDirectoryName(xmlPath) + "\\d_" + Path.GetFileName(xmlPath), false);

            foreach (var dataLine in fullLine)
            {
                Console.WriteLine(dataLine);

                int startTag = 0;
                int endTag = 0;

                string innerText = "";
                string ecrptText = "";

                string ecrptChunk = "";
                string startChunk = "";
                string endChunk = "";

                try
                {
                    // "<> </>" 에서 '>'와 '<' 사이의 값이 tag이므로 이를 읽기 위한 방법
                    for (int i = 0; i < dataLine.Length; i++)
                    {
                        if ((dataLine[i] == '>') && (startTag == 0))
                        {
                            startTag = i + 1;
                        }

                        if ((dataLine[i] == '<') && (i > startTag) && (startTag != 0))
                        {
                            endTag = i - 1;
                        }
                    }

                    // tag 값을 변환
                    if (startTag != 0 && endTag != 0)
                    {
                        for (int i = startTag; i <= endTag; i++)
                        {
                            innerText = innerText + dataLine[i];
                        }

                        ecrptChunk = RSADecrypt(innerText, privateKeyText);

                        startChunk = dataLine.Substring(0, startTag);

                        endChunk = dataLine.Substring(endTag + 1);

                        ecrptText = startChunk + ecrptChunk + endChunk;

                        writer.WriteLine(ecrptText);
                    }
                    else
                    {
                        writer.WriteLine(dataLine);
                    }
                }
                catch
                {
                    writer.WriteLine(dataLine);
                }
            }

            writer.Close();
        }

        #endregion
    }
}
