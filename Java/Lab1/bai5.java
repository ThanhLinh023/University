import java.util.Scanner;
import java.lang.Math;
import java.util.Arrays;
public class bai5 {
    public static void main(String[] args) {
        int m, n;
        Scanner input = new Scanner(System.in);
        System.out.print("Nhap vao chieu dai mang A: ");
        n = input.nextInt();
        int[] a = new int[n];
        System.out.print("Nhap vao mang A: ");
        for (int i = 0; i < n; i++)
        {
            a[i] = input.nextInt();
        }
        System.out.print("Nhap vao chieu dai mang B: ");
        m = input.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; i++)
        {
            b[i] = (int)(Math.random() * 100);
        }
        System.out.print("Mang B sau khi tao: ");
        for (int i = 0; i < m; i++)
        {
            System.out.print(b[i] + " ");
        }
        int[] c = Arrays.copyOf(a, n);
        System.arraycopy(b, m - 3, c, 0, 3);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (c[i] >= c[j])
                {
                    int temp = c[i];
                    c[i] = c[j];
                    c[j] = temp;
                }
            }
        }
        System.out.print("\nMang C sau khi tao: ");
        for (int  i = 0; i < n; i++)
        {
            System.out.print(c[i] + " ");
        }
    }
}
