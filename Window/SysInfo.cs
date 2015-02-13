using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;

namespace Window
{
    class SysInfo : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private double axisX_pos = 0;
        public double AxisXPos
        {
            get { return axisX_pos; }
            set
            {
                axisX_pos = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisXPos"));
                }
            }
        }

        private double axisY1_pos = 0;
        public double AxisY1Pos
        {
            get { return axisY1_pos; }
            set
            {
                axisY1_pos = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisY1Pos"));
                }
            }
        }

        private double axisY2_pos = 0;
        public double AxisY2Pos
        {
            get { return axisY2_pos; }
            set
            {
                axisY2_pos = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisY2Pos"));
                }
            }
        }

        private double axisZ_pos = 0;
        public double AxisZPos
        {
            get { return axisZ_pos; }
            set
            {
                axisZ_pos = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisZPos"));
                }
            }
        }

        private string axisX_state = "NON";
        public string AxisXState
        {
            get { return axisX_state; }
            set
            {
                axisX_state = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisXState"));
                }
            }
        }

        private string axisY1_state = "NON";
        public string AxisY1State
        {
            get { return axisY1_state; }
            set
            {
                axisY1_state = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisY1State"));
                }
            }
        }

        private string axisY2_state = "NON";
        public string AxisY2State
        {
            get { return axisY2_state; }
            set
            {
                axisY2_state = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisY2State"));
                }
            }
        }

        private string axisZ_state = "NON";
        public string AxisZState
        {
            get { return axisZ_state; }
            set
            {
                axisZ_state = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("AxisZState"));
                }
            }
        }

        private double time_move = 0;
        public double TimeMove
        {
            get { return time_move; }
            set
            {
                time_move = value;
                if (PropertyChanged != null)
                {
                    PropertyChanged.Invoke(this, new PropertyChangedEventArgs("TimeMove"));
                }
            }
        }
    }
}
