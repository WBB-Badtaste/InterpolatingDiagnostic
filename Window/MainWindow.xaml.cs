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

namespace Window
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        private Gcode gcode = new Gcode();
        public MainWindow()
        {
            InitializeComponent();
            GcodeDataGrid.SetBinding(DataGrid.ItemsSourceProperty, new Binding("Value") { Source = gcode, Mode = BindingMode.OneWay});
        }

        private void Button_Click_Init(object sender, RoutedEventArgs e)
        {
            int a = Backstage.Initialize(true);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string path = "Circle_200_200.txt";
            gcode.Value = FileOper.Read(ref path);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            Draw.Circle(gcode.Value, ref canvas_o);
        }
    }
    
}
