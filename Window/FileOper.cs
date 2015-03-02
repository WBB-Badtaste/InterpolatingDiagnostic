using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Window
{
    enum key
    {
        No          = 0,
        Xcoordinate = 1,
        Ycoordinate = 2,
        Endspeed    = 3,
        Time        = 4,
    }

    class FileOper
    {
        public bool Write()
        {
            return true;
        }

//         public static List<GcodeSegment> Read(ref string path)
//         {
//             List<GcodeSegment> gcode = new List<GcodeSegment>();
//             StreamReader objReader = new StreamReader(path);
//             string sLine = "";
//             while (sLine != null)
//             {
//                 sLine = objReader.ReadLine();
//                 if (sLine == null || sLine.Equals(""))
//                     return gcode;
//                 GcodeSegment segment = new GcodeSegment();
//                 key sign = key.No;
//                 int indexBuffer = 1;
//                 for(int i = 0; i < sLine.Length; ++i)
//                 {
//                     switch (sLine[i])
//                     {
//                         case 'X':
//                             sign = key.Xcoordinate;
//                             indexBuffer = i+1;
//                             break;
//                         case 'Y':
//                             sign = key.Ycoordinate;
//                             indexBuffer = i+1;
//                             break;
//                         case 'S':
//                             indexBuffer = i+1;
//                             sign = key.Endspeed;
//                             break;
//                         case 'T':
//                             indexBuffer = i+1;
//                             sign = key.Time;
//                             break;
//                         case ' ':
//                             switch (sign)
//                             {
//                                 case key.No:
//                                     segment.段号 = Convert.ToUInt32(sLine.Substring(indexBuffer, i - indexBuffer));
//                                     break;
//                                 case key.Xcoordinate:
//                                     segment.X坐标 = Convert.ToDouble(sLine.Substring(indexBuffer, i - indexBuffer));
//                                     break;
//                                 case key.Ycoordinate:
//                                     segment.Y坐标 = Convert.ToDouble(sLine.Substring(indexBuffer, i - indexBuffer));
//                                     break;
//                                 case key.Endspeed:
//                                     segment.段末速度 = Convert.ToDouble(sLine.Substring(indexBuffer, i - indexBuffer));
//                                     break;
//                                 case key.Time:
//                                     segment.运动时间 = Convert.ToDouble(sLine.Substring(indexBuffer, i - indexBuffer));
//                                     break;
//                                 default:
//                                     break;
//                             }
//                             break;
//                         default:
//                             break;
//                     }
//                 }
//                 gcode.Add(segment);
//             }
//             return gcode;
//         }
    }
}
