using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KdTree;
using KdTree.Math;

namespace kdTreeTest
{
    class Program
    {
        static void Main(string[] args)
        {
            CalKdTree();
        }

        private static void CalKdTree()
        {
            // ref : https://github.com/codeandcats/KdTree
            // ref : http://accord-framework.net/docs/html/T_Accord_Collections_KDTree_1.htm

            // define tree
            var tree = new KdTree<float, string>(3, new FloatMath());

            // define each points (3 points)
            // {x, y, z}, point name
            tree.Add(new[] { 50.0f, 80.0f, 80.0f }, "a");
            tree.Add(new[] { 20.0f, 10.0f, 20.0f }, "b");
            tree.Add(new[] { 20.0f, 10.0f, 10.0f }, "c");

            // cal. nearest neighbours
            // {x, y, z}, num of point that nearest neighbours
            var nodes = tree.GetNearestNeighbours(new[] { 30.0f, 20.0f, 10.0f }, 2);

            // show point that nearest neighbours
            Console.WriteLine("name of point : " + nodes[0].Value.ToString());
            Console.WriteLine("x : " + nodes[0].Point[0].ToString());
            Console.WriteLine("x : " + nodes[0].Point[1].ToString());
            Console.WriteLine("x : " + nodes[0].Point[2].ToString());

            return;
        }
    }
}
