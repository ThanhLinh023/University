using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTTH1
{
    internal class Program
    {
        //Khai bao cau truc Phan So
        struct PhanSo
        {
            public int tuSo, mauSo;
        }
        //Tim UCLN
        public int gcd(int a, int b)
        {
            if (b == 0) return Math.Abs(a);
            return gcd(b, a % b);
        }
        //Cau 1: Tinh chu vi duong tron
        public static void tinhChuVi()
        {
            int r;
            Console.Write("Nhap ban kinh duong tron: ");
            r = int.Parse(Console.ReadLine());
            Console.WriteLine($"Chu vi duong tron la {2 * Math.PI * r}");
        }
        //Cau 2: Tinh toan voi Phan So
        public static void tinhToanPS()
        {
            PhanSo a, b;
            Console.Write("Nhap vao phan so thu nhat: ");
            a.tuSo = int.Parse(Console.ReadLine());
            a.mauSo = int.Parse(Console.ReadLine());
            Console.Write("Nhap vao phan so thu hai: ");
            b.tuSo = int.Parse(Console.ReadLine());
            b.mauSo = int.Parse(Console.ReadLine());
            Console.WriteLine($"Hai phan so vua nhap: {a.tuSo}/{a.mauSo} va {b.tuSo}/{b.mauSo}");
            Console.WriteLine($"Tong hai phan so la {a.tuSo * b.mauSo + a.mauSo * b.tuSo}/{a.mauSo * b.mauSo}");
            Console.WriteLine($"Hieu hai phan so la {a.tuSo * b.mauSo - a.mauSo * b.tuSo}/{a.mauSo * b.mauSo}");
            Console.WriteLine($"Tich hai phan so la {a.tuSo * b.tuSo}/{a.mauSo * b.mauSo}");
            Console.WriteLine($"Thuong hai phan so la {a.tuSo * b.mauSo}/{a.mauSo * b.tuSo}");
        }
        //Cau 3: Tinh tuoi nghi huu
        public static void tinhNghiHuu()
        {
            String hoTen, gioiTinh;
            int day, month, year;
            Console.Write("Nhap ho ten: ");
            hoTen = Console.ReadLine();
            Console.Write("Nhap gioi tinh: ");
            gioiTinh = Console.ReadLine();
            Console.WriteLine("Nhap ngay thang nam sinh: ");
            day = int.Parse(Console.ReadLine());
            month = int.Parse(Console.ReadLine());
            year = int.Parse(Console.ReadLine());
            DateTime ngaySinh = new DateTime(year, month, day);
            DateTime date;
            Console.WriteLine($"Ho ten nhan vien: {hoTen}");
            Console.WriteLine($"Ngay sinh: {ngaySinh.Date}");
            Console.WriteLine($"Gioi tinh: {gioiTinh}");
            if (gioiTinh.ToLower() == "nam")
            {
                Console.WriteLine($"Ngay ve huu: {ngaySinh.Day}/{ngaySinh.Month}/{ngaySinh.Year + 60}");
            }
            else
            {
                Console.WriteLine($"Ngay ve huu: {ngaySinh.Day}/{ngaySinh.Month}/{ngaySinh.Year + 55}");
            }
        }
        //Cau 4: Xu ly chuoi
        public static void xuLyChuoi()
        {
            String x, y;
            Console.WriteLine("Nhap vao 2 chuoi: ");
            x = Console.ReadLine();
            y = Console.ReadLine();
            Console.WriteLine($"Chieu dai chuoi x: {x.Length}");
            Console.WriteLine($"3 ki tu dau chuoi x: {x.Substring(0, 3)}");
            Console.WriteLine($"3 ki tu cuoi chuoi x: {x.Substring(x.Length - 3, 3)}");
            if (x.Length >= 6)
            {
                Console.WriteLine($"Ki tu thu 6 chuoi x: {x.Substring(6, 1)}");
            }
            else
            {
                Console.WriteLine("Chuoi x co do dai nho hon 6");
            }
            String noiChuoi = x.Substring(0, 3) + y.Substring(y.Length - 3, 3);
            Console.WriteLine($"Chuoi moi: {noiChuoi}");
            String checkEqual = x.Equals(y) ? "Hai chuoi x va y bang nhau" : "Hai chuoi x va y khong bang nhau";
            Console.WriteLine(checkEqual);
            if (x.IndexOf(y) != -1)
            {
                Console.WriteLine($"Vi tri cua y trong x: {x.IndexOf(y)}");
            }
            else
            {
                Console.WriteLine("y khong ton tai trong x");
            }
            Console.Write("Cac vi tri xuat hien cua y trong x: ");
            for (int i = 0; i <= x.Length - y.Length; i++)
            {
                if (x.Substring(i, y.Length).Equals(y))
                {
                    Console.Write(i + ", ");
                }
            }
            Console.Write("\n");
        }
        //Cau 5: Tinh tien dien
        public static void tinhTienDien()
        {
            int soDien, tongTien = 0;
            Console.Write("Nhap so dien su dung: ");
            soDien = int.Parse(Console.ReadLine());
            if (soDien <= 50)
            {
                tongTien += soDien * 2000;
            }
            else if (soDien > 50 && soDien <= 100)
            {
                tongTien += 50 * 2000 + (soDien - 50) * 2500;
            }
            else
            {
                tongTien += 50 * 2000 + (soDien - 50) * 3500;
            }
            Console.WriteLine($"Tong tien dien la {tongTien} dong");
        }
        static void Main(string[] args)
        {
            int choice = -1;
            Console.WriteLine("###############################");
            Console.WriteLine("1. Bai 1");
            Console.WriteLine("2. Bai 2");
            Console.WriteLine("3. Bai 3");
            Console.WriteLine("4. Bai 4");
            Console.WriteLine("5. Bai 5");
            Console.WriteLine("6. Thoat");
            Console.WriteLine("###############################");
            while (true)
            {
                Console.Write("Chon bai chay: ");
                choice = int.Parse(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        tinhChuVi();
                        break;
                    case 2:
                        tinhToanPS();
                        break;
                    case 3:
                        tinhNghiHuu();
                        break;
                    case 4:
                        xuLyChuoi();
                        break;
                    case 5:
                        tinhTienDien();
                        break;
                    default:
                        Environment.Exit(0);
                        break;
                }
            }
        }
    }
}
