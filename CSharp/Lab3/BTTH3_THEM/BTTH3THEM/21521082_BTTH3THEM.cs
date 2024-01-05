using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BTTH3THEM
{
    internal class Program
    {
        static int ExecuteSqlCommand(SqlConnection connection, string sqlCommand)
        {
            using (SqlCommand command = new SqlCommand(sqlCommand, connection))
            {
                try
                {
                    int rowsAffected = command.ExecuteNonQuery();
                    return rowsAffected;
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                    return 0;
                }
            }
        }
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            var conString = @"Data Source=DESKTOP-9CU8EU9;Initial Catalog=QLBH_TH;Integrated Security=True";
            var connection = new SqlConnection(conString);
            Console.WriteLine("Câu 1: ");
            connection.Open();
            int cau1 = ExecuteSqlCommand(connection, "update SANPHAM1 set GIA = GIA + GIA * 0.5 where NUOCSX = 'Thai Lan'");
            Console.WriteLine($"Số sản phẩm do Thái Lan sản xuất được cập nhật giá: {cau1} sản phẩm");
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 2: ");
            int cau2 = ExecuteSqlCommand(connection, "update SANPHAM1 set GIA = GIA - GIA *0.5 where NUOCSX = 'Trung Quoc' and GIA <= 10000");
            Console.WriteLine($"Số sản phẩm do Trung Quốc sản xuất được cập nhật giá: {cau2} sản phẩm");
            connection.Close();
            connection.Open();
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 5: ");
            using (SqlCommand cau5 = new SqlCommand("select MASP, TENSP from SANPHAM1 where MASP like 'B%01'", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau5.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Mã sản phẩm: {reader["MASP"]}, Tên sản phẩm: {reader["TENSP"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 6: ");
            using (SqlCommand cau6 = new SqlCommand("select MASP, TENSP from SANPHAM1 \r\nwhere NUOCSX = 'Trung Quoc' and GIA >= 30000 and GIA <= 40000", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau6.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Mã sản phẩm: {reader["MASP"]}, Tên sản phẩm: {reader["TENSP"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 9: ");
            using (SqlCommand cau9 = new SqlCommand("select SOHD, TRIGIA, NGHD from HOADON \r\nwhere month(NGHD) = '1' and year(NGHD) = '2007'\r\norder by NGHD ASC, TRIGIA DESC", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau9.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Số hóa đơn: {reader["SOHD"]}, Trị giá: {reader["TRIGIA"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 10: ");
            using (SqlCommand cau10 = new SqlCommand("select KhachHang.MAKH, KhachHang.HOTEN from KhachHang inner join HOADON \r\non KhachHang.MAKH = HOADON.MAKH and HOADON.NGHD = '1/1/2007';", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau10.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Mã khách hàng: {reader["MAKH"]}, Họ tên: {reader["HOTEN"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 20: ");
            using (SqlCommand cau20 = new SqlCommand("select SoHD from HoaDon\r\nwhere not exists\r\n(\r\n\tselect * from SanPham where NuocSX = 'Singapore'\r\n\tand not exists \r\n\t\t(select * from CTHD \r\n\t\twhere HoaDon.SoHD = CTHD.SoHD \r\n\t\tand SanPham.MaSP = CTHD.MaSP)\r\n)", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau20.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Số hóa đơn: {reader["soHD"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 21: ");
            using (SqlCommand cau21 = new SqlCommand("select SoHD from HoaDon\r\nwhere not exists\r\n(\r\n\tselect * from SanPham where NuocSX = 'Singapore'\r\n\tand not exists \r\n\t\t(select * from CTHD \r\n\t\twhere HoaDon.SoHD = CTHD.SoHD \r\n\t\tand SanPham.MaSP = CTHD.MaSP)\r\n)\r\nand year(NgHD) = 2006", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau21.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Số hóa đơn: {reader["soHD"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 39: ");
            using (SqlCommand cau39 = new SqlCommand("select month(NgHD) as Thang, sum(TriGia) as DoanhThu from HoaDon\r\nwhere year(NgHD) = 2006\r\ngroup by month(NgHD)", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau39.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Tháng: {reader["Thang"]}, Doanh Thu: {reader["DoanhThu"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
            Console.WriteLine("-------------------------------------------");
            Console.WriteLine("Câu 40: ");
            using (SqlCommand cau40 = new SqlCommand("select SoHD, count(SoHD) as SLMua from CTHD\r\ngroup by SoHD\r\nhaving count(SoHD) >= 4", connection))
            {
                try
                {
                    using (SqlDataReader reader = cau40.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            Console.WriteLine($"Số hóa đơn: {reader["soHD"]}, Số lượng mua: {reader["SLMua"]}");
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");
                }
            }
        }
    }
}
