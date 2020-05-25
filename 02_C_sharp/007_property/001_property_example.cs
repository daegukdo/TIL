using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace test
{
    // define class with property
    class NameCard
    {
        private int age;
        private string name;

        public int Age
        {
            get
            {
                return age;
            }

            set
            {
                age = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }

            set
            {
                name = value;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            NameCard MyCard = new NameCard();

            MyCard.Age = 24;
            MyCard.Name = "sanghyun";

            Console.WriteLine("age : {0}", MyCard.Age);
            Console.WriteLine("name : {0}", MyCard.Name);

            return;
        }
    }
}
