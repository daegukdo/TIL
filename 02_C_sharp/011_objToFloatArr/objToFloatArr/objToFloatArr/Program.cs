using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace objToFloatArr
{
    class Program
    {
        static void Main(string[] args)
        {
            string objPath = "data/Femur_bone.obj";
            ObjToFltArrXYZ(objPath);
        }

        public static void ObjToFltArrXYZ(string objPath)
        {
            List<float[]> objPointsList = new List<float[]>();

            var lines = File.ReadLines(objPath);

            foreach (var line in lines)
            {
                float[] tmpArrFlt = new float[3];
                string[] tmpArrStr = line.Split(' ');

                if (tmpArrStr[0] == "v")
                {
                    tmpArrFlt[0] = float.Parse(tmpArrStr[1]);
                    tmpArrFlt[1] = float.Parse(tmpArrStr[2]);
                    tmpArrFlt[2] = float.Parse(tmpArrStr[3]);

                    objPointsList.Add(tmpArrFlt);
                }
                else if (tmpArrStr[0] == "f")
                {
                    break;
                }
            }

            // Console.WriteLine(objPointsList.Count);

            float[] targetPtn = new float[3] { -17.036f, 3.673f, 181.250f };

            return;
        }
    }
}
