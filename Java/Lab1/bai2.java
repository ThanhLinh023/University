import java.util.Scanner;

public class bai2 {
    public static void main(String[] agrs) {
        Scanner input = new Scanner(System.in);
        int a, b;
        System.out.print("Nhap vao 2 so nguyen: ");
        a = input.nextInt();
        b = input.nextInt();
        int i, max, lcm = 1;
        if (a == 0 || b == 0) {
            System.out.println("Khong co boi chung nho nhat");
        } else {
            if (a >= b) {
                max = a;
            } else {
                max = b;
            }
            i = max;
            while (true) {
                if (i % a == 0 && i % b == 0) 
                {
                    lcm = i;
                    break;
                }
                i += max;
            }
            System.out.println("Boi chung nho nhat cua " + a + " va " + b + " la: " + lcm);
        }
    }
}
