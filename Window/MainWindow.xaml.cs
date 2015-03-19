using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MahApps.Metro.Controls;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Threading;
using System.IO;

namespace Window
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        private bool bInit = false;
        private bool bMoving = false;
        private bool bWorking = false;
        private Gcode gcode = new Gcode();
        private SysInfo sysInfo = new SysInfo();
        private AxisInfo axisInfoX = new AxisInfo();
        private AxisInfo axisInfoY1 = new AxisInfo();
        private AxisInfo axisInfoY2 = new AxisInfo();
        private AxisInfo axisInfoZ = new AxisInfo();
        InSeg[] inSeg = new InSeg[200];

        private string nodeName  = "NY4112_node";
        private string axisName1 = "DEF_AXIS_1";
        private string axisName2 = "DEF_AXIS_2";
        private string axisName3 = "DEF_AXIS_3";
        private string axisName4 = "DEF_AXIS_4";

        private IntPtr pNodeName;
        private IntPtr pAxisNameX;
        private IntPtr pAxisNameY1;
        private IntPtr pAxisNameY2;
        private IntPtr pAxisNameZ;

        public MainWindow()
        {
            InitializeComponent();

            pNodeName = Marshal.AllocHGlobal(nodeName.Length);
            pAxisNameX = Marshal.AllocHGlobal(axisName1.Length);
            pAxisNameY1 = Marshal.AllocHGlobal(axisName2.Length);
            pAxisNameY2 = Marshal.AllocHGlobal(axisName3.Length);
            pAxisNameZ = Marshal.AllocHGlobal(axisName4.Length);

            pNodeName = Marshal.StringToHGlobalAnsi(nodeName);
            pAxisNameX = Marshal.StringToHGlobalAnsi(axisName1);
            pAxisNameY1 = Marshal.StringToHGlobalAnsi(axisName2);
            pAxisNameY2 = Marshal.StringToHGlobalAnsi(axisName3);
            pAxisNameZ = Marshal.StringToHGlobalAnsi(axisName4);

            GcodeDataGrid.SetBinding(DataGrid.ItemsSourceProperty, new Binding("Value") { Source = gcode, Mode = BindingMode.OneWay});
            XStatus.SetBinding(TextBox.TextProperty, new Binding("AxisXState") { Source = sysInfo, Mode = BindingMode.OneWay });
            Y1Status.SetBinding(TextBox.TextProperty, new Binding("AxisY1State") { Source = sysInfo, Mode = BindingMode.OneWay });
            Y2Status.SetBinding(TextBox.TextProperty, new Binding("AxisY2State") { Source = sysInfo, Mode = BindingMode.OneWay });
            ZStatus.SetBinding(TextBox.TextProperty, new Binding("AxisZState") { Source = sysInfo, Mode = BindingMode.OneWay });
            XPos.SetBinding(TextBox.TextProperty, new Binding("AxisXPos") { Source = sysInfo, Mode = BindingMode.OneWay });
            Y1Pos.SetBinding(TextBox.TextProperty, new Binding("AxisY1Pos") { Source = sysInfo, Mode = BindingMode.OneWay });
            Y2Pos.SetBinding(TextBox.TextProperty, new Binding("AxisY2Pos") { Source = sysInfo, Mode = BindingMode.OneWay });
            ZPos.SetBinding(TextBox.TextProperty, new Binding("AxisZPos") { Source = sysInfo, Mode = BindingMode.OneWay });
            MoveTime.SetBinding(TextBox.TextProperty, new Binding("TimeMove") { Source = sysInfo, Mode = BindingMode.OneWay });
            
            bWorking = true;
            Thread thread = new Thread(new ThreadStart(ThreadMathod));
            thread.IsBackground = true;
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();
        }

        private void ThreadMathod()
        {
            double posBuffer = 0.0;
            IntPtr stateBuffer = new IntPtr();
            stateBuffer = Marshal.AllocHGlobal(50);
            bool bMoveBegined = false;
            DateTime timeBeginMove = DateTime.Now;
            DateTime timeCurrent = timeBeginMove;
            double buffer = 0.0;
            double offset = 0.0;

            double lastPosX = 0.0, lastPosY = 0.0;
            bool bDraw = false;
            while (bWorking)
            {
                Thread.CurrentThread.Join(50);
                if (!bInit)
                    continue;
                Backstage.GetAxisPosition(pAxisNameX, ref posBuffer);
                sysInfo.AxisXPos = posBuffer;
                Backstage.GetAxisPosition(pAxisNameY1, ref posBuffer);
                sysInfo.AxisY1Pos = posBuffer;
                Backstage.GetAxisPosition(pAxisNameY2, ref posBuffer);
                sysInfo.AxisY2Pos = posBuffer;
                Backstage.GetAxisPosition(pAxisNameZ, ref posBuffer);
                sysInfo.AxisZPos = posBuffer;
                
                Backstage.GetAxisStatus(pAxisNameX, stateBuffer);
                sysInfo.AxisXState = Marshal.PtrToStringAnsi(stateBuffer);
                Backstage.GetAxisStatus(pAxisNameY1, stateBuffer);
                sysInfo.AxisY1State = Marshal.PtrToStringAnsi(stateBuffer);
                Backstage.GetAxisStatus(pAxisNameY2, stateBuffer);
                sysInfo.AxisY2State = Marshal.PtrToStringAnsi(stateBuffer);
                Backstage.GetAxisStatus(pAxisNameZ, stateBuffer);
                sysInfo.AxisZState = Marshal.PtrToStringAnsi(stateBuffer);
                if (bMoving)
                {
                    if (bMoveBegined)
                    {
                        timeCurrent = DateTime.Now;
                        buffer =timeCurrent.Minute * 60 + timeCurrent.Second + (double)timeCurrent.Millisecond / 1000 - timeBeginMove.Minute * 60 - timeBeginMove.Second - (double)timeBeginMove.Millisecond / 1000 + offset;
                        if(buffer < 0)
                        {
                            timeBeginMove = DateTime.Now;
                            offset += sysInfo.TimeMove;
                            sysInfo.TimeMove = Math.Round(timeCurrent.Minute * 60 + timeCurrent.Second + (double)timeCurrent.Millisecond / 1000 - timeBeginMove.Minute * 60 - timeBeginMove.Second - (double)timeBeginMove.Millisecond / 1000 + offset);
                        }
                        else
                            sysInfo.TimeMove = Math.Round(buffer);
                        if (bDraw)
                        {
                            DrawLine(lastPosX, lastPosY, sysInfo.AxisXPos, sysInfo.AxisY1Pos,true);
                            lastPosX = sysInfo.AxisXPos;
                            lastPosY = sysInfo.AxisY1Pos;
                        }
                        else
                        {
                            Draw.Clear_f(ref canvas_f);
                            lastPosX = sysInfo.AxisXPos;
                            lastPosY = sysInfo.AxisY1Pos;
                            bDraw = true;
                        }
                    }
                    else
                    {
                        timeBeginMove = DateTime.Now;
                        bMoveBegined = true;
                    }
                }
                else
                    if (bMoveBegined)
                        bMoveBegined = false;
            }
            Marshal.FreeHGlobal(stateBuffer);
        }

        private void Button_Click_Init(object sender, RoutedEventArgs e)
        {
            bool bSim = (bool)cb_Simulation.IsChecked;
            if (bInit)
            {
                listBox_result.Items.Add(new TextBox() { Text = "已初始化！" });
                return;
            }
            listBox_result.Items.Add(new TextBox() { Text = "正在初始化..." });
           
            if (Backstage.Initialize(ref bSim)            != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisNameX)  != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisNameY1) != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisNameY2) != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisNameZ)  != Backstage.OK )
            {
                listBox_result.Items.Add(new TextBox() { Text = "初始化失败！" });
            }
            else
            {
                listBox_result.Items.Add(new TextBox() { Text = "完成初始化。" });
                bInit = true;
                Seletion();

                if (Backstage.RocksGantryInitialize(pNodeName, pAxisNameX, pAxisNameY1, pAxisNameY2, pAxisNameZ) == Backstage.OK)
                {
                    listBox_result.Items.Add(new TextBox() { Text = "完成龙门结构初始化。" });
                }
                else
                {
                    listBox_result.Items.Add(new TextBox() { Text = "龙门结构初始化失败！" });
                }
            }          
        }

        private void Button_Click_LoadFile(object sender, RoutedEventArgs e)
        {
            //string path = "Circle_200_200.txt";
            //gcode.Value = FileOper.Read(ref path);
            //listBox_result.Items.Add(new TextBox() { Text = "完成基代码读取。" });
        }

        private void Button_Click_Draw(object sender, RoutedEventArgs e)
        {
            Draw.Circle(gcode.Value, ref canvas_o);
            listBox_result.Items.Add(new TextBox() { Text = "完成目标图形。" });
        }

        private void Window_Closing(object sender, CancelEventArgs e)
        {
            if (!bInit)
                return;
            bWorking = false;
            Thread.Sleep(1000);
            if (Backstage.RocksGantryTerminal() == Backstage.OK &&
                Backstage.Terminate()           == Backstage.OK )
                bInit = false;
            Marshal.FreeHGlobal(pNodeName);
            Marshal.FreeHGlobal(pAxisNameX);
            Marshal.FreeHGlobal(pAxisNameY1);
            Marshal.FreeHGlobal(pAxisNameY2);
            Marshal.FreeHGlobal(pAxisNameZ);
        }

        private void Button_Click_Align(object sender, RoutedEventArgs e)
        {
            if(!bInit)
                listBox_result.Items.Add(new TextBox() { Text = "请先初始化！" });

            if (Backstage.AlignAxis(pAxisNameX)  != Backstage.OK ||
                Backstage.AlignAxis(pAxisNameY1) != Backstage.OK ||
                Backstage.AlignAxis(pAxisNameY2) != Backstage.OK ||
                Backstage.AlignAxis(pAxisNameZ)  != Backstage.OK )
            {
                listBox_result.Items.Add(new TextBox() { Text = "寻相失败！" });
            }
            else
            {
                listBox_result.Items.Add(new TextBox() { Text = "完成寻相。" });
            }
        }

        private void Button_Click_Home(object sender, RoutedEventArgs e)
        {
            if (!bInit)
                listBox_result.Items.Add(new TextBox() { Text = "请先初始化！" });

            if (Backstage.HomeAxis(pAxisNameX)  != Backstage.OK ||
                Backstage.HomeAxis(pAxisNameY1) != Backstage.OK ||
                Backstage.HomeAxis(pAxisNameY2) != Backstage.OK ||
                Backstage.HomeAxis(pAxisNameZ)  != Backstage.OK )
            {
                listBox_result.Items.Add(new TextBox() { Text = "回零失败！" });
            }
            else
            {
                listBox_result.Items.Add(new TextBox() { Text = "完成回零。" });
            }
        }

        private void Button_Click_Reset(object sender, RoutedEventArgs e)
        { 
            if (!bInit)
                listBox_result.Items.Add(new TextBox() { Text = "请先初始化！" });

            if (Backstage.ResetAxis(pAxisNameX)  != Backstage.OK ||
                Backstage.ResetAxis(pAxisNameY1) != Backstage.OK ||
                Backstage.ResetAxis(pAxisNameY2) != Backstage.OK ||
                Backstage.ResetAxis(pAxisNameZ)  != Backstage.OK )
            {
                listBox_result.Items.Add(new TextBox() { Text = "复位失败！" });
            }
            else
            {
                listBox_result.Items.Add(new TextBox() { Text = "完成复位。" });
            }
        }
         
        private void Button_Click_Interpolate(object sender, RoutedEventArgs e)
        {
            bMoving = true;

//             unsafe
//             {
//                 fixed (InSeg* p = &inSeg[0])
//                 {
//                     int sum = inSeg.Length;
//                     int a = Backstage.MoveInterpolating(p, sum, true);
//                 }
//             }

            if (Backstage.RocksGanrtyArcInterpolation(150, 0, 0.1, 360.0) != Backstage.OK)
            {
                listBox_result.Items.Add(new TextBox() { Text = "启动插补运动失败！" });
            }
            else 
            {
                listBox_result.Items.Add(new TextBox() { Text = "正常启动插补运动。" });
            }
        }

        private void Button_Click_GenerateFile(object sender, RoutedEventArgs e)
        {
            unsafe
            {
                fixed (InSeg* p = &inSeg[0])
                {
                    double dCurX = 0; 
                    double dCurY = 0;
                    Backstage.GetAxisPosition(pAxisNameX, ref dCurX);
                    Backstage.GetAxisPosition(pAxisNameY1, ref dCurY);
                    double dRadius = 150;
                    int sum = inSeg.Length;
                    int a = Backstage.GetInSeg_Circle(ref dCurX, ref dCurY, ref dRadius, p, ref sum);
                }
            }
            List<GcodeSegment> gc = new List<GcodeSegment>();
            foreach (InSeg seg in inSeg)
            {
                GcodeSegment Segment = new GcodeSegment();
                Segment.X坐标         = seg.dPosX;
                Segment.Y坐标         = seg.dPosY;
                Segment.段号          = (uint)seg.iNo;
                Segment.X轴段末速度   = seg.dVelX;
                Segment.Y轴段末速度   = seg.dVelY;
                Segment.运动时间      = seg.dTime;
                gc.Add(Segment);
            }
            gcode.Value = gc;
        }

        public void DrawLine(double lastPosX, double lastPosY, double nextPosX, double nextPosY,bool bRed = false)
        {
            this.Dispatcher.Invoke((Action)(() =>
            {
                Draw.DrawLine_f(lastPosX, lastPosY, nextPosX, nextPosY, ref canvas_f, bRed);
            }));
        }

        private void ComboBox_SelectionChanged_Axis(object sender, SelectionChangedEventArgs e)
        {
            if (!bInit)
                return;
            Seletion();
        }

        private void Seletion()
        {
            double dVel = 0, dAcc = 0, dJerk = 0;
            switch (combox_axis.SelectedIndex)
            {
                case 0:
                    home_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Vel") { Source = axisInfoX, Mode = BindingMode.TwoWay });
                    home_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Acc") { Source = axisInfoX, Mode = BindingMode.TwoWay });
                    home_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Jerk") { Source = axisInfoX, Mode = BindingMode.TwoWay });
                    motion_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Vel") { Source = axisInfoX, Mode = BindingMode.TwoWay });
                    motion_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Acc") { Source = axisInfoX, Mode = BindingMode.TwoWay });
                    motion_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Jerk") { Source = axisInfoX, Mode = BindingMode.TwoWay });
                    emergency_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Stop_Acc") { Source = axisInfoX, Mode = BindingMode.TwoWay });

                    Backstage.GetAxisHomePars(pAxisNameX, ref dVel, ref dAcc, ref dJerk);
                    axisInfoX.Home_Vel = dVel;
                    axisInfoX.Home_Acc = dAcc;
                    axisInfoX.Home_Jerk = dJerk;
                    Backstage.GetAxisMotionPars(pAxisNameX, ref dVel, ref dAcc, ref dJerk);
                    axisInfoX.Motion_Vel = dVel;
                    axisInfoX.Motion_Acc = dAcc;
                    axisInfoX.Motion_Jerk = dJerk;
                    Backstage.GetAxisStopPars(pAxisNameX, ref dAcc);
                    axisInfoX.Stop_Acc = dAcc;
                    break;
                case 1:
                    home_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Vel") { Source = axisInfoY1, Mode = BindingMode.TwoWay });
                    home_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Acc") { Source = axisInfoY1, Mode = BindingMode.TwoWay });
                    home_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Jerk") { Source = axisInfoY1, Mode = BindingMode.TwoWay });
                    motion_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Vel") { Source = axisInfoY1, Mode = BindingMode.TwoWay });
                    motion_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Acc") { Source = axisInfoY1, Mode = BindingMode.TwoWay });
                    motion_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Jerk") { Source = axisInfoY1, Mode = BindingMode.TwoWay });
                    emergency_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Stop_Acc") { Source = axisInfoY1, Mode = BindingMode.TwoWay });

                    Backstage.GetAxisHomePars(pAxisNameY1, ref dVel, ref dAcc, ref dJerk);
                    axisInfoY1.Home_Vel = dVel;
                    axisInfoY1.Home_Acc = dAcc;
                    axisInfoY1.Home_Jerk = dJerk;
                    Backstage.GetAxisMotionPars(pAxisNameY1, ref dVel, ref dAcc, ref dJerk);
                    axisInfoY1.Motion_Vel = dVel;
                    axisInfoY1.Motion_Acc = dAcc;
                    axisInfoY1.Motion_Jerk = dJerk;
                    Backstage.GetAxisStopPars(pAxisNameY1, ref dAcc);
                    axisInfoY1.Stop_Acc = dAcc;
                    break;
                case 2:
                    home_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Vel") { Source = axisInfoY2, Mode = BindingMode.TwoWay });
                    home_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Acc") { Source = axisInfoY2, Mode = BindingMode.TwoWay });
                    home_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Jerk") { Source = axisInfoY2, Mode = BindingMode.TwoWay });
                    motion_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Vel") { Source = axisInfoY2, Mode = BindingMode.TwoWay });
                    motion_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Acc") { Source = axisInfoY2, Mode = BindingMode.TwoWay });
                    motion_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Jerk") { Source = axisInfoY2, Mode = BindingMode.TwoWay });
                    emergency_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Stop_Acc") { Source = axisInfoY2, Mode = BindingMode.TwoWay });

                    Backstage.GetAxisHomePars(pAxisNameY2, ref dVel, ref dAcc, ref dJerk);
                    axisInfoY2.Home_Vel = dVel;
                    axisInfoY2.Home_Acc = dAcc;
                    axisInfoY2.Home_Jerk = dJerk;
                    Backstage.GetAxisMotionPars(pAxisNameY2, ref dVel, ref dAcc, ref dJerk);
                    axisInfoY2.Motion_Vel = dVel;
                    axisInfoY2.Motion_Acc = dAcc;
                    axisInfoY2.Motion_Jerk = dJerk;
                    Backstage.GetAxisStopPars(pAxisNameY2, ref dAcc);
                    axisInfoY2.Stop_Acc = dAcc;
                    break;
                case 3:
                    home_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Vel") { Source = axisInfoZ, Mode = BindingMode.TwoWay });
                    home_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Acc") { Source = axisInfoZ, Mode = BindingMode.TwoWay });
                    home_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Home_Jerk") { Source = axisInfoZ, Mode = BindingMode.TwoWay });
                    motion_speed.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Vel") { Source = axisInfoZ, Mode = BindingMode.TwoWay });
                    motion_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Acc") { Source = axisInfoZ, Mode = BindingMode.TwoWay });
                    motion_jerk.SetBinding(NumericUpDown.DataContextProperty, new Binding("Motion_Jerk") { Source = axisInfoZ, Mode = BindingMode.TwoWay });
                    emergency_acceleration.SetBinding(NumericUpDown.DataContextProperty, new Binding("Stop_Acc") { Source = axisInfoZ, Mode = BindingMode.TwoWay });

                    Backstage.GetAxisHomePars(pAxisNameZ, ref dVel, ref dAcc, ref dJerk);
                    axisInfoZ.Home_Vel = dVel;
                    axisInfoZ.Home_Acc = dAcc;
                    axisInfoZ.Home_Jerk = dJerk;
                    Backstage.GetAxisMotionPars(pAxisNameZ, ref dVel, ref dAcc, ref dJerk);
                    axisInfoZ.Motion_Vel = dVel;
                    axisInfoZ.Motion_Acc = dAcc;
                    axisInfoZ.Motion_Jerk = dJerk;
                    Backstage.GetAxisStopPars(pAxisNameZ, ref dAcc);
                    axisInfoZ.Stop_Acc = dAcc;
                    break;
                default:
                    break;
            }
        }
    }
}
