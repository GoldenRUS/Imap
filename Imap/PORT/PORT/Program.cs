using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;

namespace PORT
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Count() > 0)
            {
                SerialPort sp = new SerialPort("COM11", 9600);
                sp.Open();
                sp.Write(args[0]);
                sp.Close();
            }
        }
    }
}
