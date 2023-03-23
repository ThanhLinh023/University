import java.util.Scanner;
import java.lang.Math;
public class bai6 {
    static boolean isPrime(int n)
    {
        if (n < 2) return false;
        else
        {
            for (int i = 2; i <= Math.sqrt(n); i++)
            {
                if (n % i == 0) return false;
            }
            return true;
        }
    }
    public static void main(String[] args) {
        int n, m;
        Scanner input = new Scanner(System.in);
        System.out.print("Nhap vao kich thuoc mang: ");
        n = input.nextInt();
        m = input.nextInt();
        int[][] a = new int[n][m];
        System.out.print("Nhap vao mang\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = input.nextInt();
            }
        }
        int max = a[0][0];
        int indexI = -1, indexJ = -1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (a[i][j] >= max)
                {
                    max = a[i][j];
                    indexI = i;
                    indexJ = j;
                }
            }
        }
        System.out.print("Gia tri lon nhat cua mang la " + max + " tai dong " + indexI + ", cot " + indexJ);
        System.out.print("\nCac phan tu la so nguyen to: ");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isPrime(a[i][j]) == true)
                {
                    System.out.print(a[i][j] + " ");
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int k = i + 1; k < n; k++)
                {
                    if (a[i][j] >= a[k][j])
                    {
                        int temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                }
            }
        }
        System.out.print("\nMang A sau khi sap xep: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                System.out.print(a[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
