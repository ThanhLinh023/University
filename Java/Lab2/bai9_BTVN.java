import java.util.ArrayList;
import java.util.Scanner;

public class bai9_BTVN {
    static Scanner input = new Scanner(System.in);
    static Scanner inputString = new Scanner(System.in);
    static ArrayList<Electric> arr = new ArrayList<>();
    void input()
    {
        String cID, cName, doBill;
        float eNum, uCost;
        int choose;
        while (true)
        {
            System.out.println("Choose type of customer:\n1.Living\n2.Business\n3.Manufacture");
            choose = input.nextInt();
            if (choose == 1)
            {
                System.out.print("Enter customer ID: ");
                cID = inputString.nextLine();
                if (cID.equals(""))
                {
                    break;
                }
                System.out.print("Enter customer name: ");
                cName = inputString.nextLine();
                System.out.print("Enter date of bill (dd-mm-yyyy): ");
                doBill = inputString.nextLine();
                System.out.print("Enter electric number: ");
                eNum = input.nextFloat();
                System.out.print("Enter cost of a unit: ");
                uCost = input.nextFloat();
                System.out.print("Enter dinh muc: ");
                int dm = input.nextInt();
                Living a = new Living(cID, cName, doBill, eNum, uCost, dm);
                arr.add(a);
            }
            else if (choose == 2)
            {
                System.out.print("Enter customer ID: ");
                cID = inputString.nextLine();
                if (cID.equals(""))
                {
                    break;
                }
                System.out.print("Enter customer name: ");
                cName = inputString.nextLine();
                System.out.print("Enter date of bill (dd-mm-yyyy): ");
                doBill = inputString.nextLine();
                System.out.print("Enter electric number: ");
                eNum = input.nextFloat();
                System.out.print("Enter cost of a unit: ");
                uCost = input.nextFloat();
                Business b = new Business(cID, cName, doBill, eNum, uCost);
                arr.add(b);
            }
            else
            {
                System.out.print("Enter customer ID: ");
                cID = inputString.nextLine();
                if (cID.equals(""))
                {
                    break;
                }
                System.out.print("Enter customer name: ");
                cName = inputString.nextLine();
                System.out.print("Enter date of bill (dd-mm-yyyy): ");
                doBill = inputString.nextLine();
                System.out.print("Enter electric number: ");
                eNum = input.nextFloat();
                System.out.print("Enter cost of a unit: ");
                uCost = input.nextFloat();
                System.out.print("Enter type of electric (2. 2-phase 3. 3-phase): ");
                int phase = input.nextInt();
                Manufacture c = new Manufacture(cID, cName, doBill, eNum, uCost, phase);
                arr.add(c);
            }
        }
    }
    public static void main(String[] args)
    {
        bai9_BTVN b9 = new bai9_BTVN();
        b9.input();
        String monthFind, yearFind;
        System.out.print("Enter month to find bill: ");
        monthFind = inputString.nextLine();
        System.out.print("Enter year to find bill: ");
        yearFind = inputString.nextLine();
        String ans = monthFind + "-" + yearFind;
        System.out.println("-----------------------");
        boolean checked = false;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr.get(i).getDOBill().contains(ans) == true)
            {
                arr.get(i).showCustomer();
                System.out.println("-----------------------");
                checked = true;
            }
            if (checked == false)
            {
                System.out.println("Cannot find bill!");
            }
        }
    }
}
interface IElectric
{
    void showCustomer();
    float calculateBill();
}
abstract class Electric implements IElectric
{
    protected String customerID;
    protected String customerName;
    protected String dateOfBill;
    protected float electricNumber;
    protected float unitCost;
    protected int type;
    Electric () {}
    Electric(String cid, String cname, String cdate, float cENum, float cunitCost)
    {
        customerID = cid;
        customerName = cname;
        dateOfBill = cdate;
        electricNumber = cENum;
        unitCost = cunitCost;
    }
    void setType(int a) {type = a;}
    int getType() {return type;}
    String getCID() {return customerID;}
    String getCN() {return customerName;}
    String getDOBill() {return dateOfBill;}
    public void showCustomer()
    {
        System.out.println("Customer ID: " + customerID);
        System.out.println("Customer Name: " + customerName);
        System.out.println("Date of bill: " + dateOfBill);
        System.out.println("Number of used electric: " + electricNumber);
        System.out.println("Cost of a unit: " + unitCost);
        System.out.println("To money: " + calculateBill());
    }
}
class Living extends Electric
{
    protected int DinhMuc;
    Living () {}
    Living(String cid, String cname, String cday, float cENum, float cunitCost, int DinhMuc)
    {
        super(cid, cname, cday, cENum, cunitCost);
        this.DinhMuc = DinhMuc;
        super.setType(1);
    }
    public void showCustomer()
    {
        super.showCustomer();
        System.out.println("Dinh muc: " + DinhMuc);
    }
    public float calculateBill()
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
class Business extends Electric
{
    Business() {}
    Business(String cid, String cname, String cday, float cENum, float cunitCost)
    {
        super(cid, cname, cday, cENum, cunitCost);
        super.setType(2);
    }
    public void showCustomer()
    {
        super.showCustomer();
    }
    public float calculateBill()
    {
        if (electricNumber <= 400)
        {
            return electricNumber * unitCost;
        }
        else
        {
            return (float)(electricNumber * unitCost * 0.05);
        }
    }
}
class Manufacture extends Electric
{
    protected int electricType;
    Manufacture() {}
    Manufacture(String cid, String cname, String cday, float cENum, float cunitCost, int ctype)
    {
        super(cid, cname, cday, cENum, cunitCost);
        electricType = ctype;
        super.setType(3);
    }
    public void showCustomer()
    {
        super.showCustomer();
        System.out.println("Electric type: " + electricType + " phase");
    }
    public float calculateBill()
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