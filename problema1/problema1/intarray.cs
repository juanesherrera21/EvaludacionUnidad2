using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problema1
{
    class intarray
    {
        //atribute:
        private int[] arr;
        private int leght;

        public int[] Arr { get => arr; set => arr = value; }
        public int Leght { get => leght; set => leght = value; }


        //methodos:
        public intarray(int leght) {
            Arr = new int[leght];
            this.Leght = leght;
        }

    }
}
