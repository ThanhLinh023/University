import java.util.Scanner;
public class bai4 {
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Nhap vao 1 so duong: ");
        int num = in.nextInt();
        System.out.print("Uoc so cua " + num + ": ");
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                System.out.print(i + " ");
            }
        }
    }
}
