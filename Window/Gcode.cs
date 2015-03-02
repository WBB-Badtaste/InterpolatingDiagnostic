using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;

namespace Window
{
    public class GcodeSegment
    {
        public uint 段号 { get; set; }
        public double X坐标 { get; set; }
        public double Y坐标 { get; set; }
        public double X轴段末速度 { get; set; }
        public double Y轴段末速度 { get; set; }
        public double 运动时间 { get; set; }
    }

    class Gcode : INotifyPropertyChanged
    {
        private List<GcodeSegment> listCode = new List<GcodeSegment>();

        public event PropertyChangedEventHandler PropertyChanged;

        public List<GcodeSegment> Value
        {
            get { return listCode; }
            set
            {
                if (listCode != value)
                {
                    listCode = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Value"));
                    }
                }
            }
        }
    }
}
