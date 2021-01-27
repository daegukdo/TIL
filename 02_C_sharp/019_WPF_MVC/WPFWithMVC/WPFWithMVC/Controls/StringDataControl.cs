using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using WPFWithMVC.Models;

namespace WPFWithMVC.Controls
{
    class StringDataControl
    {
        private StringData _stringData1 = null;
        private StringData _stringData2 = null;

        public StringDataControl()
        {
            _stringData1 = new StringData();
            _stringData2 = new StringData();

            _stringData1.StrData = "data1";
            _stringData2.StrData = "data2";
        }

        public EventHandler SendStrData = null;

        public void DoActionStrData(object sender, EventArgs e)
        {
            string key = sender as string;
            string senderStr = "";

            switch (key)
            {
                case "A":
                    if (_stringData1 != null)
                    {
                        senderStr = _stringData1.StrData;
                    }
                    break;
                case "B":
                    if (_stringData2 != null)
                    {
                        senderStr = _stringData2.StrData;
                    }
                    break;
            }

            if (SendStrData != null) { SendStrData(senderStr, EventArgs.Empty); }
        }
    }
}
