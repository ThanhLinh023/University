using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTTH2_BTTHEM
{
    //Class Electric la class cha
    public abstract class Electric
    {
        protected string customerID;
        protected string customerName;
        protected string dateOfBill;
        protected float electricNumber;
        protected float unitCost;

        public Electric() { }
        public Electric(string cid, string cname, string cdate, float cENum, float cunitCost)
        {
            customerID = cid;
            customerName = cname;
            dateOfBill = cdate;
            electricNumber = cENum;
            unitCost = cunitCost;
        }
        public string getDOBill() { return dateOfBill; }
        public void showCustomer()
        {
            Console.WriteLine($"Ma khach hang: {customerID}");
            Console.WriteLine($"Ten khach hang: {customerName}");
            Console.WriteLine($"Ngay hoa don: {dateOfBill}");
            Console.WriteLine($"So luong dien: {electricNumber}");
            Console.WriteLine($"Don gia: {unitCost}");
            Console.WriteLine($"Thanh tien: {calculateBill()}");
        }
        public abstract float calculateBill();
    }
    public class Living : Electric
    {
        protected float DinhMuc;
        Living() { }
        public Living(String cid, String cname, string cday, float cENum, float cunitCost, float DinhMuc) : base(cid, cname, cday, cENum, cunitCost)
        {
            this.DinhMuc = DinhMuc;
        }
        public void showCustomer()
        {
            base.showCustomer();
            Console.WriteLine("Dinh muc: " + DinhMuc);
        }
        public override float calculateBill()
        {
            if (electricNumber <= DinhMuc)
            {
                return electricNumber * unitCost;
            }
            else
            {
                return electricNumber * unitCost * DinhMuc + (electricNumber - DinhMuc) * unitCost * 2;
            }
        }
    }
    public class Business : Electric
    {
        Business() { }
        public Business(String cid, String cname, string cday, float cENum, float cunitCost) : base(cid, cname, cday, cENum, cunitCost)
        {
        }
        public void showCustomer()
        {
            base.showCustomer();
        }
        public override float calculateBill()
        {
            if (electricNumber <= 400)
            {
                return electricNumber * unitCost;
            }
            else
            {
                return (float)(electricNumber * unitCost * 1.05);
            }
        }
    }
    public class Manufacture : Electric
    {
        protected int electricType;
        Manufacture() { }
        public Manufacture(string cid, string cname, string cday, float cENum, float cunitCost, int ctype) : base(cid, cname, cday, cENum, cunitCost)
        {
            electricType = ctype;
        }
        public void showCustomer()
        {
            base.showCustomer();
            Console.WriteLine("Loai dien: " + electricType + " phase");
        }
        public override float calculateBill()
        {
            if (electricType == 2)
            {
                if (electricNumber > 200)
                {
                    return (float)(electricNumber * unitCost * 0.98);
                }
                else
                {
                    return electricNumber * unitCost;
                }
            }
            else
            {
                if (electricNumber > 150)
                {
                    return (float)(electricNumber * unitCost * 0.97);
                }
                else
                {
                    return electricNumber * unitCost;
                }
            }
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Electric> electricCustomer = new List<Electric>();
            string cId, cName;
            string billDate;
            float eNum, unitCost, defaultElectric;
            int choice = -1, phase;
            while (true)
            {
                Console.WriteLine("Chon loai khach hang: 1.Sinh hoat -- 2.Kinh doanh -- 3.San xuat");
                Electric e;
                choice = int.Parse(Console.ReadLine());
                if (choice > 0 && choice < 4)
                {
                    Console.Write("Nhap ma khach hang: "); cId = Console.ReadLine();
                    if (cId == "")
                    {
                        break; // Neu ma khach hang rong thi dung chuong trinh
                    }
                    Console.Write("Nhap ten khach hang: "); cName = Console.ReadLine();
                    Console.Write("Nhap ngay hoa don (dd/MM/yyyy): "); billDate = Console.ReadLine();
                    Console.Write("Nhap so luong dien: "); eNum = float.Parse(Console.ReadLine());
                    Console.Write("Nhap don gia: "); unitCost = float.Parse(Console.ReadLine());
                    if (choice == 1)
                    {
                        Console.Write("Nhap dinh muc: "); defaultElectric = int.Parse(Console.ReadLine());
                        e = new Living(cId, cName, billDate, eNum, unitCost, defaultElectric);
                    }
                    else if (choice == 2)
                    {
                        e = new Business(cId, cName, billDate, eNum, unitCost);
                    }
                    else
                    {
                        Console.Write("Nhap loai dien: "); phase = int.Parse(Console.ReadLine());
                        e = new Manufacture(cId, cName, billDate, eNum, unitCost, phase);
                    }
                    electricCustomer.Add(e);
                    Console.WriteLine("-----------------------------------");
                }
                else
                {
                    Console.WriteLine("Hay chon lai");
                    Console.WriteLine("-----------------------------------");
                }
            }
            Console.Write("Nhap thang hoa don:");
            string month = Console.ReadLine();
            Console.Write("Nhap nam hoa don: ");
            string year = Console.ReadLine();
            foreach (var khachHang in electricCustomer)
            {
                if (khachHang.getDOBill().Contains($"{month}/{year}"))
                {
                    khachHang.showCustomer();
                }
            }
        }
    }
}
