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
        InSeg[] inSeg = new InSeg[200];

        private string nodeName = "NY4112_node";
        private string axisName1 = "DEF_AXIS_1";
        private string axisName2 = "DEF_AXIS_2";
        private string axisName3 = "DEF_AXIS_3";
        private string axisName4 = "DEF_AXIS_4";

        private IntPtr pNodeName;
        private IntPtr pAxisName1;
        private IntPtr pAxisName2;
        private IntPtr pAxisName3;
        private IntPtr pAxisName4;

        public MainWindow()
        {
            InitializeComponent();

            pNodeName = Marshal.AllocHGlobal(nodeName.Length);
            pAxisName1 = Marshal.AllocHGlobal(axisName1.Length);
            pAxisName2 = Marshal.AllocHGlobal(axisName2.Length);
            pAxisName3 = Marshal.AllocHGlobal(axisName3.Length);
            pAxisName4 = Marshal.AllocHGlobal(axisName4.Length);

            pNodeName = Marshal.StringToHGlobalAnsi(nodeName);
            pAxisName1 = Marshal.StringToHGlobalAnsi(axisName1);
            pAxisName2 = Marshal.StringToHGlobalAnsi(axisName2);
            pAxisName3 = Marshal.StringToHGlobalAnsi(axisName3);
            pAxisName4 = Marshal.StringToHGlobalAnsi(axisName4);

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
                Thread.CurrentThread.Join(100);
                if (!bInit)
                    continue;
                Backstage.GetAxisPosition(pAxisName1, ref posBuffer);
                sysInfo.AxisXPos = posBuffer;
                Backstage.GetAxisPosition(pAxisName2, ref posBuffer);
                sysInfo.AxisY1Pos = posBuffer;
                Backstage.GetAxisPosition(pAxisName3, ref posBuffer);
                sysInfo.AxisY2Pos = posBuffer;
                Backstage.GetAxisPosition(pAxisName4, ref posBuffer);
                sysInfo.AxisZPos = posBuffer;
                
                Backstage.GetAxisStatus(pAxisName1, stateBuffer);
                sysInfo.AxisXState = Marshal.PtrToStringAnsi(stateBuffer);
                Backstage.GetAxisStatus(pAxisName2, stateBuffer);
                sysInfo.AxisY1State = Marshal.PtrToStringAnsi(stateBuffer);
                Backstage.GetAxisStatus(pAxisName3, stateBuffer);
                sysInfo.AxisY2State = Marshal.PtrToStringAnsi(stateBuffer);
                Backstage.GetAxisStatus(pAxisName4, stateBuffer);
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
                            DrawLine(lastPosX, lastPosY, sysInfo.AxisXPos, sysInfo.AxisY1Pos);
                            lastPosX = sysInfo.AxisXPos;
                            lastPosY = sysInfo.AxisY1Pos;
                        }
                        else
                        {
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
           
            if (Backstage.Initialize(ref bSim)           != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisName1) != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisName2) != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisName3) != Backstage.OK ||
                Backstage.AddAxis(pNodeName, pAxisName4) != Backstage.OK )
            {
                listBox_result.Items.Add(new TextBox() { Text = "初始化失败！" });
            }
            else
            {
                listBox_result.Items.Add(new TextBox() { Text = "完成初始化。" });
                bInit = true;
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

            if (Backstage.Terminate() == 0)
                bInit = false;

            Marshal.FreeHGlobal(pNodeName);
            Marshal.FreeHGlobal(pAxisName1);
            Marshal.FreeHGlobal(pAxisName2);
            Marshal.FreeHGlobal(pAxisName3);
            Marshal.FreeHGlobal(pAxisName4);
        }

        private void Button_Click_Align(object sender, RoutedEventArgs e)
        {
            if(!bInit)
                listBox_result.Items.Add(new TextBox() { Text = "请先初始化！" });

            if (Backstage.AlignAxis(pAxisName1) != Backstage.OK ||
                Backstage.AlignAxis(pAxisName2) != Backstage.OK ||
                Backstage.AlignAxis(pAxisName3) != Backstage.OK ||
                Backstage.AlignAxis(pAxisName4) != Backstage.OK )
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

            if (Backstage.HomeAxis(pAxisName1) != Backstage.OK ||
                Backstage.HomeAxis(pAxisName2) != Backstage.OK ||
                Backstage.HomeAxis(pAxisName3) != Backstage.OK ||
                Backstage.HomeAxis(pAxisName4) != Backstage.OK )
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

            if (Backstage.ResetAxis(pAxisName1) != Backstage.OK ||
                Backstage.ResetAxis(pAxisName2) != Backstage.OK ||
                Backstage.ResetAxis(pAxisName3) != Backstage.OK ||
                Backstage.ResetAxis(pAxisName4) != Backstage.OK )
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
            unsafe
            {
                fixed (InSeg* p = &inSeg[0])
                {
                    int sum = inSeg.Length;
                    int a = Backstage.MoveInterpolating(p, sum, true);
                }
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
                    Backstage.GetAxisPosition(pAxisName1, ref dCurX);
                    Backstage.GetAxisPosition(pAxisName2, ref dCurY);
                    double dRadius = 150;
                    int sum = inSeg.Length;
                    int a = Backstage.GetInSeg_Circle(ref dCurX, ref dCurY, ref dRadius, p, ref sum);
                }
            }
            List<GcodeSegment> gc = new List<GcodeSegment>();
            foreach (InSeg seg in inSeg)
            {
                GcodeSegment Segment = new GcodeSegment();
                Segment.X坐标 = seg.dPosX;
                Segment.Y坐标 = seg.dPosY;
                Segment.段号 = (uint)seg.iNo;
                Segment.X轴段末速度 = seg.dVelX;
                Segment.Y轴段末速度 = seg.dVelY;
                Segment.运动时间 = seg.dTime;
                gc.Add(Segment);
            }
            gcode.Value = gc;
        }

        public void DrawLine(double lastPosX, double lastPosY, double nextPosX, double nextPosY)
        {
            this.Dispatcher.Invoke((Action)(() =>
            {
                Draw.drawLine(lastPosX, lastPosY, nextPosX, nextPosY, ref canvas_f);
            }));
        }
    }
}
