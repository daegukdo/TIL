using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using EventBasedMVVMwithControl.Models;

namespace EventBasedMVVMwithControl.Controls
{
    class StringDataControl
    {
        private StringData _stringData = null;

        public StringDataControl()
        {
            _stringData = new StringData();
        }

        public EventHandler SendStrData = null;

        public void DoActionStrData(object sender, EventArgs e)
        {
            string key = sender as string;
            string tmpStr = "";

            string args = null;

            switch (key)
            {
                case "A":
                    tmpStr = "AAA";
                    break;
                case "B":
                    tmpStr = "BBB";
                    break;
            }

            _stringData.StrData = tmpStr;

            if (SendStrData != null) { SendStrData(_stringData.StrData, EventArgs.Empty); }
        }
    }
}
