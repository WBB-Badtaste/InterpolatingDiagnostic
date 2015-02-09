using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace Window
{
    class Backstage
    {
        [DllImport("Backstage.dll", EntryPoint = "Initialize", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int Initialize(bool bSim);
        [DllImport("Backstage.dll", EntryPoint = "Terminate", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int Terminate();
    }
}
