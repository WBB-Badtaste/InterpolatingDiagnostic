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
            if (list.Count <= 0) 
                return;
            canvas.Children.Clear();
            double diffX = list[0].X坐标 - list[list.Count / 2].X坐标;
            double diffY = list[0].Y坐标 - list[list.Count / 2].Y坐标;
            double d = Math.Sqrt(diffX * diffX + diffY * diffY);
            double rate = Math.Min(canvas.ActualWidth, canvas.ActualHeight) / d;
            double minX = list[0].X坐标, minY = list[0].Y坐标;
            foreach (GcodeSegment seg in list)
            {
                if (seg.X坐标 < minX)
                    minX = seg.X坐标;
                if (seg.Y坐标 < minY)
                    minY = seg.Y坐标;
            }
            double xOffset = (minX + d / 2) * rate - canvas.ActualWidth / 2;
            double yOffset = (minY + d / 2) * rate - canvas.ActualHeight / 2;
            for (int i = 0; i < list.Count - 1; ++i)
            {
                Point startPt = new Point(list[i].X坐标 * rate - xOffset, list[i].Y坐标 * rate - yOffset);
                Point endPt = new Point(list[i + 1].X坐标 * rate - xOffset, list[i + 1].Y坐标 * rate - yOffset);
                LineGeometry myLineGeometry = new LineGeometry() { StartPoint = startPt, EndPoint = endPt };
                Path myPath = new Path() { Stroke = Brushes.Blue, StrokeThickness = 2, Data = myLineGeometry };
                canvas.Children.Add(myPath);
                myPath.HorizontalAlignment = HorizontalAlignment.Center;
                myPath.VerticalAlignment = VerticalAlignment.Center;
            }
        }
    }
}
