using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;

namespace Window
{
    class AxisInfo : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private double home_vel = 0.0;//回零速度
        public double Home_Vel
        {
            get { return home_vel; }
            set
            {
                if (home_vel != value)
                {
                    home_vel = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Home_Vel"));
                    }
                }
            }
        }

        private double home_acc = 0.0;//回零加速度
        public double Home_Acc
        {
            get { return home_acc; }
            set
            {
                if (home_acc != value)
                {
                    home_acc = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Home_Acc"));
                    }
                }
            }
        }

        private double home_jerk = 0.0;//回零加加速度
        public double Home_Jerk
        {
            get { return home_jerk; }
            set
            {
                if (home_jerk != value)
                {
                    home_jerk = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Home_Jerk"));
                    }
                }
            }
        }

        private double motion_vel = 0.0;//运动速度
        public double Motion_Vel
        {
            get { return motion_vel; }
            set
            {
                if (motion_vel != value)
                {
                    motion_vel = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Motion_Vel"));
                    }
                }
            }
        }

        private double motion_acc = 0.0;//运动加速度
        public double Motion_Acc
        {
            get { return motion_acc; }
            set
            {
                if (motion_acc != value)
                {
                    motion_acc = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Motion_Acc"));
                    }
                }
            }
        }

        private double motion_jerk = 0.0;//运动加加速度
        public double Motion_Jerk
        {
            get { return motion_jerk; }
            set
            {
                if (motion_jerk != value)
                {
                    motion_jerk = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Motion_Jerk"));
                    }
                }
            }
        }

        private double stop_acc = 0.0;// 急停加速度
        public double Stop_Acc
        {
            get { return stop_acc; }
            set
            {
                if (stop_acc != value)
                {
                    stop_acc = value;
                    if (PropertyChanged != null)
                    {
                        PropertyChanged.Invoke(this, new PropertyChangedEventArgs("Stop_Acc"));
                    }
                }
            }
        }
    }
}
