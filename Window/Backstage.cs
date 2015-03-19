using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace Window
{
    public struct InSeg
    {
        public int iNo;
        public double dPosX;
        public double dPosY;
        public double dVelX;
        public double dVelY;
        public double dTime;
    };

    class Backstage
    {
        [DllImport("Backstage.dll", EntryPoint = "Initialize", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int Initialize(ref bool bSim);
        [DllImport("Backstage.dll", EntryPoint = "Terminate", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int Terminate();
        [DllImport("Backstage.dll", EntryPoint = "AddAxis", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int AddAxis(IntPtr noName, IntPtr axName);
        [DllImport("Backstage.dll", EntryPoint = "AlignAxis", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int AlignAxis(IntPtr axName);
        [DllImport("Backstage.dll", EntryPoint = "HomeAxis", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int HomeAxis(IntPtr axName);
        [DllImport("Backstage.dll", EntryPoint = "ResetAxis", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int ResetAxis(IntPtr axName);
        [DllImport("Backstage.dll", EntryPoint = "GetAxisPosition", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int GetAxisPosition(IntPtr axName, ref double encoderValue);
        [DllImport("Backstage.dll", EntryPoint = "GetAxisStatus", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int GetAxisStatus(IntPtr axName, IntPtr strState);
        [DllImport("Backstage.dll", EntryPoint = "GetInSeg_Circle", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        unsafe public extern static int GetInSeg_Circle(ref double dCurX, ref double dCurY, ref double dRadius, InSeg* pSeg, ref int iSegSum);
        [DllImport("Backstage.dll", EntryPoint = "MoveInterpolating", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        unsafe public extern static int MoveInterpolating(InSeg* pSeg, int iSum, bool bAbsolute);
        [DllImport("Backstage.dll", EntryPoint = "GetAxisHomePars", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int GetAxisHomePars(IntPtr axName,ref double dMaxVel,ref double dMaxAcc,ref double dMaxJerk);
        [DllImport("Backstage.dll", EntryPoint = "SetAxisHomePars", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int SetAxisHomePars(IntPtr axName,double dMaxVel,double dMaxAcc,double dMaxJerk);
        [DllImport("Backstage.dll", EntryPoint = "GetAxisMotionPars", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int GetAxisMotionPars(IntPtr axName,ref double dMaxVel,ref double dMaxAcc,ref double dMaxJerk);
        [DllImport("Backstage.dll", EntryPoint = "SetAxisMotionPars", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int SetAxisMotionPars(IntPtr axName,double dMaxVel,double dMaxAcc,double dMaxJerk);
        [DllImport("Backstage.dll", EntryPoint = "GetAxisStopPars", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int GetAxisStopPars(IntPtr axName,ref double dMaxAcc);
        [DllImport("Backstage.dll", EntryPoint = "SetAxisStopPars", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int SetAxisStopPars(IntPtr axName,double dMaxAcc);
        [DllImport("Backstage.dll", EntryPoint = "RocksGantryInitialize", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int RocksGantryInitialize(IntPtr node, IntPtr axX, IntPtr axY1, IntPtr axY2, IntPtr axZ);
        [DllImport("Backstage.dll", EntryPoint = "RocksGantryTerminal", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int RocksGantryTerminal();
        [DllImport("Backstage.dll", EntryPoint = "RocksGanrtyArcInterpolation", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static int RocksGanrtyArcInterpolation(double cX, double cY, double time, double angle);

        public static int OK                = 10000;
        public static int INITALIZE_FAIL    = 10001;
        public static int TERMINATE_FAIL    = 10002;
        public static int ADDNODE_FAIL      = 10003;
        public static int ADDAXIS_FAIL      = 10004;
        public static int ALIGNAXIS_FAIL    = 10005;
        public static int HOMEAXIS_FAIL     = 10006;
        public static int RESETAXIS_FAIL    = 10007;
    }
}
