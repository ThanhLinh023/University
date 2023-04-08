import java.util.Scanner;

public class bai7_BTVN {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a, b, c;
        System.out.print("Number of Pedions: ");
        a = in.nextInt();
        System.out.print("Number of Zattackers: ");
        b = in.nextInt();
        System.out.print("Number of Carriers: ");
        c = in.nextInt();
        Robot arr[] = new Robot[a + b + c];
        int choose;
        for (int i = 0; i < (a + b + c); i++)
        {
            System.out.print("Choose type of robot (1. Pedion 2. Zattacker 3. Carrier): ");
            choose = in.nextInt();
            if (choose == 1)
            {
                arr[i] = new Pedion();
                arr[i].setType(1);
            }
            if (choose == 2)
            {
                arr[i] = new Zattacker();
                arr[i].setType(2);
            }
            if (choose == 3)
            {
                arr[i] = new Carrier();
                arr[i].setType(3);
            }
            arr[i].input();
        }
        int sumPedion = 0, sumZattacker = 0, sumCarrier = 0;
        System.out.println("--------------------------------");
        for (int i = 0; i < (a + b + c); i++)
        {
            if (arr[i].getType() == 1)
            {
                System.out.println("Pedion " + (int)(i + 1) + " use " + arr[i].calculateEnergy() + " energies");
                sumPedion += arr[i].calculateEnergy();
            }
            if (arr[i].getType() == 2)
            {
                System.out.println("Zattacker " + (int)(i + 1) + " use " + arr[i].calculateEnergy() + " energies");
                sumZattacker += arr[i].calculateEnergy();
            }
            if (arr[i].getType() == 3)
            {
                System.out.println("Carrier " + (int)(i + 1) + " use " + arr[i].calculateEnergy() + " energies");
                sumCarrier += arr[i].calculateEnergy();
            }
        }
        System.out.println("--------------------------------");
        if (sumPedion > Math.max(sumZattacker, sumCarrier))
        {
            System.out.println("Pedion uses most energies, total " + sumPedion + " energies");
        }
        if (sumZattacker > Math.max(sumPedion, sumCarrier))
        {
            System.out.println("Zattacker uses most energies, total " + sumZattacker + " energies");
        }
        if (sumCarrier > Math.max(sumZattacker, sumPedion))
        {
            System.out.println("Carrier uses most energies, total " + sumCarrier + " energies");
        }
    }
}

abstract class Robot
{
    protected int mass;
    protected int type;
    abstract int calculateEnergy();
    abstract void input();
    void setType(int type) {this.type = type;}
    int getType() {return type;}
}
class Pedion extends Robot
{
    private int flexible;
    Pedion() {mass = 20;}
    void input()
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter flexible of Pedion (1 -> 5): ");
        flexible = in.nextInt();
    }
    int calculateEnergy()
    {
        return mass * 10 + (flexible + 1) * 10 / 2;
    }
}
class Zattacker extends Robot
{
    private int power;
    Zattacker() {mass = 50;}
    void input()
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter power of Zattacker (20 -> 30): ");
        power = in.nextInt();
    }
    int calculateEnergy()
    {
        return mass * 10 + power * power * 10;
    }
}
class Carrier extends Robot
{
    private int energy;
    Carrier() {mass = 30;}
    void input()
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter energy of Carrier (50 -> 100): ");
        energy = in.nextInt();
    }
    int calculateEnergy()
    {
        return mass * 10 + 4 * energy * 10;
    }
}