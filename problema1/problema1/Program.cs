using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problema1
{
    class Program
    {

        static void Main(string[] args)
        {
            
            intarray parr = new intarray(100);
            Program obj = new Program();
            obj.initIntArray(parr);
            obj.printArray(parr);
            //GC.Collect();
            //GC.WaitForPendingFinalizers();
            Console.ReadKey();
        }

        public void initIntArray(intarray v1) {
           
            for (int i = 0; i < v1.Leght; i++)
            {
                v1.Arr[i] = i;
            }

        }

        public void printArray(intarray v1)
        {
            for (int i = 0; i < v1.Leght; i++)
            {
                Console.WriteLine("parr[" + i + "]" + ":" + v1.Arr[i]);
            }
        }

    }
}
