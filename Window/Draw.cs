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
        public static void Circle( List<GcodeSegment> list, ref Canvas canvas)
        {
            double r = Math.Min(canvas.ActualWidth, canvas.ActualHeight);
            for (int i = 0; i < list.Count -1; ++i )
            {
                Point startPt = new Point(list[i].X坐标 * r / 400, list[i].Y坐标 * r / 400);
                Point endPt = new Point(list[i+1].X坐标, list[i+1].Y坐标);
                LineGeometry myLineGeometry = new LineGeometry() { StartPoint = startPt, EndPoint = endPt };
                Path myPath = new Path() { Stroke = Brushes.Blue, StrokeThickness = 2, Data = myLineGeometry };
                canvas.Children.Add(myPath);
                myPath.
            }
        }
    }
}
