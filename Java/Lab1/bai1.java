import java.util.Scanner;
public class bai1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a, b;
        System.out.print("Nhap vao 2 so nguyen: ");
        a = input.nextInt();
        b = input.nextInt();
        int tmp1, tmp2;
        tmp1 = a;
        tmp2 = b;
        while (tmp1 != tmp2)
        {
            if (tmp1 > tmp2)
            {
                tmp1 = tmp1 - tmp2;
            }
            else{
                tmp2 = tmp2 - tmp1;
            }
        }
        System.out.println("Uoc so chung cua " + a + " va " + b + " la: " + tmp1);
    }
}
