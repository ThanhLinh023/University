using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace BTTH2
{
    //Class TaiKhoan
    public class TaiKhoan
    {
        private long soTK;
        private string tenTK;
        private double soTien;
        public long SoTK
        {
            get { return soTK; }
            set { soTK = value; }
        }
        public string TenTK
        {
            get { return tenTK; }
            set { tenTK = value; }
        }
        public double SoTien
        {
            get { return soTien; }
            set { soTien = value; }
        }
        public TaiKhoan() { }
        public TaiKhoan(long soTK, string tenTK, double soTien = 10)
        {
            this.soTK = soTK;
            this.tenTK = tenTK;
            this.soTien = soTien;
        }
        public void toString()
        {
            Console.WriteLine($"So tai khoan: {soTK}");
            Console.WriteLine($"Ten tai khoan: {tenTK}");
            Console.WriteLine($"So du tai khoan: ${soTien}");
        }
        public Boolean napTien(double st)
        {
            if (st > 0)
            {
                soTien += st;
                return true;
            }
            return false;
        }
        public Boolean rutTien(double st)
        {
            if (soTien > 0 && st > 0 && soTien > st)
            {
                soTien -= st * 1.1;
                return true;
            }
            return false;
        }
    }
    //Class Sach, SachTieuThuyet, SachTrinhTham
    public class Sach
    {
        private long maSach;
        private string tenSach;
        private double donGia;
        private int soLuong;
        private string nhaXuatBan;
        public long MaSach
        {
            get { return maSach; }
            set { maSach = value; }
        }
        public string TenSach
        {
            get { return tenSach; }
            set { tenSach = value; }
        }
        public double DonGia
        {
            get { return donGia; }
            set { donGia = value; }
        }
        public int SoLuong
        {
            get { return soLuong; }
            set { soLuong = value; }
        }
        public string NXB
        {
            get { return nhaXuatBan; }
            set { nhaXuatBan = value; }
        }
        public Sach() { }
        public Sach(long maSach, string tenSach, double donGia, int soLuong, string nhaXuatBan)
        {
            this.maSach = maSach;
            this.tenSach = tenSach;
            this.donGia = donGia;
            this.soLuong = soLuong;
            this.nhaXuatBan = nhaXuatBan;
        }
        public virtual void toString()
        {
            Console.WriteLine("###############################");
            Console.WriteLine($"Ma sach: {maSach}");
            Console.WriteLine($"Ten sach: {tenSach}");
            Console.WriteLine($"Don gia: {donGia}");
            Console.WriteLine($"So luong: {soLuong}");
            Console.WriteLine($"Nha xuat ban: {nhaXuatBan}");
        }
        public virtual double thanhTien()
        {
            return soLuong * donGia;
        }
    }
    class SachTieuThuyet : Sach
    {
        private Boolean tinhTrang;
        public Boolean TinhTrang
        {
            get => tinhTrang;
            set => tinhTrang = value;
        }
        public SachTieuThuyet() { }
        public SachTieuThuyet(long maSach, string tenSach, double donGia, int soLuong, string nhaXuatBan, Boolean tinhTrang)
        : base(maSach, tenSach, donGia, soLuong, nhaXuatBan)
        {
            this.tinhTrang = tinhTrang;
        }
        public override void toString()
        {
            if (tinhTrang)
            {
                base.toString();
                Console.WriteLine("Tinh trang: sach moi");
            }
            else
            {
                base.toString();
                Console.WriteLine("Tinh trang: sach cu");
            }
        }
        public override double thanhTien()
        {
            if (tinhTrang)
            {
                return base.thanhTien();
            }
            else
            {
                return base.thanhTien() * 1.2;
            }
        }
    }
    public class SachTrinhTham : Sach
    {
        private float thue;
        public float Thue
        {
            get => thue;
            set => thue = value;
        }
        public SachTrinhTham() { }
        public SachTrinhTham(long maSach, string tenSach, double donGia, int soLuong, string nhaXuatBan, float thue)
        : base(maSach, tenSach, donGia, soLuong, nhaXuatBan)
        {
            this.thue = thue;
        }
        public override void toString()
        {
            base.toString();
            Console.WriteLine($"Thue: {thue}");
        }
        public override double thanhTien()
        {
            return base.thanhTien() + thue;
        }
    }
    internal class Program
    {
        //Bai tap 1
        public static void Bai1()
        {
            TaiKhoan abc = new TaiKhoan();
            Console.Write("Nhap vao so tai khoan: ");
            abc.SoTK = long.Parse(Console.ReadLine());
            Console.Write("Nhap vao ten tai khoan: ");
            abc.TenTK = Console.ReadLine();
            Console.Write("Nhap vao so du tai khoan: ");
            abc.SoTien = double.Parse(Console.ReadLine());
            abc.toString();
            int stNap, stRut;
            Console.Write("Nhap vao so tien muon nap: "); stNap = int.Parse(Console.ReadLine());
            Console.Write("Nhap vao so tien muon rut: "); stRut = int.Parse(Console.ReadLine());
            if (abc.napTien(stNap))
            {
                Console.WriteLine($"Nap tien thanh cong, so du hien tai: ${abc.SoTien}");
            }
            else
            {
                Console.WriteLine("So tien phai lon hon 0");
            }
            if (abc.rutTien(stRut))
            {
                Console.WriteLine($"Rut tien thanh cong, so du hien tai: ${abc.SoTien}");
            }
            else
            {
                Console.WriteLine("So tien rut phai nho hon so du tai khoan va phai lon hon 0");
            }
        }
        //Bai tap 2
        public static void Bai2()
        {
            Sach book1 = new SachTieuThuyet(123, "Romeo and Juliet", 5000, 2, "Kim Dong", false);
            Sach book2 = new SachTrinhTham(150, "Detective Conan", 10000, 3, "Kim Dong", 2000);
            book1.toString();
            Console.WriteLine($"Tong tien sach {book1.TenSach} la {book1.thanhTien()} dong");
            book2.toString();
            Console.WriteLine($"Tong tien sach {book2.TenSach} la {book2.thanhTien()} dong");
        }
        //Tinh average
        public static double getAverage<T>(List<T> numList)
        {
            double result = 0.0;
            foreach (var num in numList)
            {
                result += double.Parse(num.ToString());
            }
            return result / numList.Count;
        }
        //Bai tap 3
        public static void Bai3()
        {
            List<int> listInt = new List<int> {1,5,3,7,2,5,4,6,9};
            List<float> listFloat = new List<float> {5.2f, 2.25f, 8.5f, 9.1f, 10.2f, 6.4f};
            Console.WriteLine($"Average of integer list: {getAverage(listInt)}");
            Console.WriteLine($"Average of float list: {getAverage(listFloat)}");
        }
        static void Main(string[] args)
        {
            int choice = -1;
            Console.WriteLine("###############################");
            Console.WriteLine("1. Bai 1");
            Console.WriteLine("2. Bai 2");
            Console.WriteLine("3. Bai 3");
            Console.WriteLine("4. Thoat");
            Console.WriteLine("###############################");
            while (true)
            {
                Console.Write("Chon bai chay: ");
                choice = int.Parse(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        Bai1();
                        break;
                    case 2:
                        Bai2();
                        break;
                    case 3:
                        Bai3();
                        break;
                    default:
                        Environment.Exit(0);
                        break;
                }
            }
        }
    }
}
