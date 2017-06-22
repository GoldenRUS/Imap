using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.IO.Ports;

namespace PORT
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                //string port = File.ReadLines("port.txt").First();
                string port = "";
                foreach (string s in SerialPort.GetPortNames())
                {
                    SerialPort sp = new SerialPort(s, 9600);
                    sp.Open();
                    sp.Write(args[0]);
                    sp.Close();
                }
                
                
            }
        }
    }
}
