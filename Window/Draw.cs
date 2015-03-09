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
        public static void Circle( List<GcodeSegment> list, ref Canvas canvas)
        {
            if (list.Count <= 0) 
                return;
            canvas.Children.Clear();
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
            {
                Point startPt = new Point(list[i].X坐标 * m_rate - m_xOffset, list[i].Y坐标 * m_rate - m_yOffset);
                Point endPt = new Point(list[i + 1].X坐标 * m_rate - m_xOffset, list[i + 1].Y坐标 * m_rate - m_yOffset);
                LineGeometry myLineGeometry = new LineGeometry() { StartPoint = startPt, EndPoint = endPt };
                Path myPath = new Path() { Stroke = Brushes.Blue, StrokeThickness = 2, Data = myLineGeometry };
                canvas.Children.Add(myPath);
                myPath.HorizontalAlignment = HorizontalAlignment.Center;
                myPath.VerticalAlignment = VerticalAlignment.Center;
            }
        }
        public static void drawLine(double lastPosX, double lastPosY, double nextPosX, double nextPosY, ref Canvas canvas)
        {
            Point startPt = new Point(lastPosX * m_rate - m_xOffset, lastPosY * m_rate - m_yOffset);
            Point endPt = new Point(nextPosX * m_rate - m_xOffset, nextPosY * m_rate - m_yOffset);
            LineGeometry myLineGeometry = new LineGeometry() { StartPoint = startPt, EndPoint = endPt };
            Path myPath = new Path() { Stroke = Brushes.Blue, StrokeThickness = 2, Data = myLineGeometry };
            canvas.Children.Add(myPath);
            myPath.HorizontalAlignment = HorizontalAlignment.Center;
            myPath.VerticalAlignment = VerticalAlignment.Center;
        }
    }
}
