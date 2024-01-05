using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Data.SqlClient;
using System.Data;

namespace BTTH3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            var conString = @"Data Source=DESKTOP-9CU8EU9;Initial Catalog=QLBH_TH;Integrated Security=True";
            var connection = new SqlConnection(conString);
            try
            {
                connection.Open();
                if (connection.State == ConnectionState.Open)
                {
                    Console.WriteLine("Kết nối thành công");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Kết nối thất bại");
                Console.WriteLine(e.Message);
            }
            finally
            {
                connection.Close();
            }
        }
    }
}
