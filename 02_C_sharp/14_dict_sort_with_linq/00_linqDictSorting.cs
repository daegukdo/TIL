using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace linqDictSorting
{
    class Program
    {
        static void Main(string[] args)
        {
            // define model
            LinqDictSortingModel ldsm = new LinqDictSortingModel();

            // set data
            ldsm.StackData();

            // show original data
            Console.WriteLine("init. data");
            ldsm.ShowDictData();
            ldsm.ShowSortedDictData();

            // sort data
            ldsm.SortDataUsingLinq();

            // show sorted data
            Console.WriteLine("init. data");
            ldsm.ShowDictData();
            ldsm.ShowSortedDictData();

            return;
        }
    }

    class LinqDictSortingModel
    {
        private Dictionary<int, double> _dictData = null;
        private Dictionary<int, double> _dictSortedData = null;

        public LinqDictSortingModel()
        {
            _dictData = new Dictionary<int, double>();
            _dictSortedData = new Dictionary<int, double>();
        }

        public void StackData()
        {
            _dictData.Add(1, 3.14d);
            _dictData.Add(2, 8.41d);
            _dictData.Add(3, 1.23d);
            _dictData.Add(4, 5.97d);
            _dictData.Add(5, 3.86d);
        }

        public void SortDataUsingLinq()
        {
            var tmpList = _dictData.ToList();
            tmpList.Sort((pair1, pair2) => pair1.Value.CompareTo(pair2.Value));

            foreach (var item in tmpList)
            {
                _dictSortedData.Add(item.Key, item.Value);
            }
        }

        public void ShowDictData()
        {
            foreach (var item in _dictData)
            {
                Console.WriteLine(String.Format("key : {0}, value : {1}", item.Key, item.Value));
            }
        }

        public void ShowSortedDictData()
        {
            foreach (var item in _dictSortedData)
            {
                Console.WriteLine(String.Format("key : {0}, value : {1}", item.Key, item.Value));
            }
        }
    }
}
