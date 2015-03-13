using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Controls;
using System.Windows.Shapes;
using System.Windows;
using System.Windows.Media;

namespace Window
{
    class Draw
    {
        private static double m_rate = 0.0;
        private static double m_xOffset = 0.0, m_yOffset = 0.0;
        private static List<Path> m_lpath_o = new List<Path>(), m_lpath_f = new List<Path>();
        public static void Circle( List<GcodeSegment> list, ref Canvas canvas)
        {
            if (list.Count <= 0) 
                return;
            Clear_o(ref canvas);
            double diffX = list[0].X坐标 - list[list.Count / 2].X坐标;
            double diffY = list[0].Y坐标 - list[list.Count / 2].Y坐标;
            double d = Math.Sqrt(diffX * diffX + diffY * diffY);
            m_rate = Math.Min(canvas.ActualWidth, canvas.ActualHeight) / d;
            double minX = list[0].X坐标, minY = list[0].Y坐标;
            foreach (GcodeSegment seg in list)
            {
                if (seg.X坐标 < minX)
                    minX = seg.X坐标;
                if (seg.Y坐标 < minY)
                    minY = seg.Y坐标;
            }
            m_xOffset = (minX + d / 2) * m_rate - canvas.ActualWidth / 2;
            m_yOffset = (minY + d / 2) * m_rate - canvas.ActualHeight / 2;
            for (int i = 0; i < list.Count - 1; ++i)
                DrawLine_o(list[i].X坐标, list[i].Y坐标, list[i + 1].X坐标, list[i + 1].Y坐标, ref canvas);
        }
        public static void Clear_f(ref Canvas canvas)
        {
            foreach (Path path in m_lpath_f)
            {
                canvas.Children.Remove(path);
            }
            m_lpath_f.Clear();
        }
        public static void Clear_o(ref Canvas canvas)
        {
            foreach (Path path in m_lpath_f)
            {
                canvas.Children.Remove(path);
            }
            m_lpath_o.Clear();
        }
        public static void DrawLine_o(double lastPosX, double lastPosY, double nextPosX, double nextPosY, ref Canvas canvas,bool bRed=false)
        {
            Path path = new Path()
            {
                Stroke = bRed ? Brushes.Red : Brushes.Blue,
                Data = new LineGeometry()
                {
                    StartPoint = new Point(lastPosX * m_rate - m_xOffset, -(lastPosY * m_rate) - m_yOffset),
                    EndPoint = new Point(nextPosX * m_rate - m_xOffset, -(nextPosY * m_rate) - m_yOffset)
                },
                HorizontalAlignment = HorizontalAlignment.Center,
                VerticalAlignment = VerticalAlignment.Center
            };
            m_lpath_o.Add(path);
            canvas.Children.Add(path);
        }

        public static void DrawLine_f(double lastPosX, double lastPosY, double nextPosX, double nextPosY, ref Canvas canvas, bool bRed = true)
        {
            Path path = new Path()
                    {
                        Stroke = bRed ? Brushes.Red : Brushes.Blue,
                        Data = new LineGeometry()
                        {
                            StartPoint = new Point(lastPosX * m_rate - m_xOffset, -(lastPosY * m_rate) - m_yOffset),
                            EndPoint = new Point(nextPosX * m_rate - m_xOffset, -(nextPosY * m_rate) - m_yOffset)
                        },
                        HorizontalAlignment = HorizontalAlignment.Center,
                        VerticalAlignment = VerticalAlignment.Center
                    };
            m_lpath_f.Add(path);
            canvas.Children.Add(path);
        }
    }
}
