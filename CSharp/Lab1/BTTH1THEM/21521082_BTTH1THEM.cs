using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTTH1THEM
{
    internal class Program
    {
        //Tim UCLN
        public static int gcd(int a, int b)
        {
            if (b == 0) return Math.Abs(a);
            else return gcd(b, a% b);
        }
        static void Main(string[] args)
        {
            int a, b;
            Console.Write("Nhap vao 2 so: ");
            a = int.Parse(Console.ReadLine());
            b = int.Parse(Console.ReadLine());
            Console.WriteLine($"UCLN cua {a} va {b} la {gcd(a,b)}");
            int tuSo, mauSo;
            Console.Write("Nhap tu so va mau so: ");
            tuSo = int.Parse(Console.ReadLine());
            mauSo = int.Parse(Console.ReadLine());
            Console.WriteLine($"Phan so truoc khi rut gon: {tuSo}/{mauSo}");
            Console.WriteLine($"Phan so sau khi rut gon: {tuSo / gcd(tuSo, mauSo)}/{mauSo / gcd(tuSo, mauSo)}");
            int n;
            Console.Write("Nhap vao so n: ");
            n = int.Parse(Console.ReadLine());
            Console.Write($"Cac so le tu 0 den {n} la: ");
            for (int i = 0; i <= n; i++)
            {
                if (i % 2 != 0) Console.Write(i + " ");
            }
            Console.Write("\n");
            int d, m, y, dateNo, weekNo;
            Console.Write("Nhap ngay: ");
            d = int.Parse(Console.ReadLine());
            Console.Write("Nhap thang: ");
            m = int.Parse(Console.ReadLine());
            Console.Write("Nhap nam: ");
            y = int.Parse(Console.ReadLine());
            DateTime ngayDaNhap = new DateTime(y, m, d);
            dateNo = (int)ngayDaNhap.DayOfWeek + 1;
            weekNo = (new GregorianCalendar(GregorianCalendarTypes.Localized)).GetWeekOfYear(ngayDaNhap, CalendarWeekRule.FirstFourDayWeek, DayOfWeek.Monday);
            Console.WriteLine($"Ngay {ngayDaNhap.ToString("dd/MM/yyyy")} la ngay thu {dateNo} va la tuan thu {weekNo} trong nam");
        }
    }
}
