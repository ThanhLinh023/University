import java.util.Scanner;
import java.lang.Math;
public class bai3 {
    public static void main(String [] args)
    {
        int ts, ms;
        Scanner in = new Scanner(System.in);
        System.out.print("Nhap vao tu so va mau so: ");
        ts = in.nextInt();
        ms = in.nextInt();
        while (ms == 0)
        {
            System.out.println("Mau so phai khac 0!");
            System.out.print("Nhap lai mau so: ");
            ms = in.nextInt();
        }
        if (ts != 0)
        {
            int tmp1, tmp2;
            tmp1 = Math.abs(ts);
            tmp2 = Math.abs(ms);
            while (tmp1 != tmp2)
            {
                if (tmp1 > tmp2)
                {
                    tmp1 = tmp1 - tmp2;
                }
                else
                {
                    tmp2 = tmp2 - tmp1;
                }
            }
        ts = ts / tmp1;
        ms = ms / tmp1;
        }
        if (ms < 0)
        {
            ts = -ts;
            ms = -ms;
        }
        System.out.print("Phan so sau khi rut gon: ");
        if (ts == 0)
        {
            System.out.print("0");
        }
        else if (ms == 1)
        {
            System.out.print(ts);
        }
        else
        {
            System.out.print(ts + "/" + ms);
        }
    }
}