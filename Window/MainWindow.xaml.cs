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

namespace Window
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        public MainWindow()
        {
            InitializeComponent();

            List<GcodeSegment> Gcode = new List<GcodeSegment>()
            {
                new GcodeSegment(){段号=0,X坐标=200,Y坐标=0,段末速度=0.01,运动时间=2}
            };

            GcodeDataGrid.ItemsSource = Gcode;
        }

        private void Button_Click_Init(object sender, RoutedEventArgs e)
        {
            int a = Backstage.Initialize(true);
        }
    }
    public class GcodeSegment
    {
        public uint 段号 { get; set; }
        public double X坐标 { get; set; }
        public double Y坐标 { get; set; }
        public double 段末速度 { get; set; }    
        public double 运动时间 { get; set; }
    }
}
