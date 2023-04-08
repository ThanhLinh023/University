import java.util.Scanner;
public class bai6_BTVN {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of Internal trips: ");
        int internal = input.nextInt();
        System.out.print("Enter number of External trips: ");
        int external = input.nextInt();
        InternalTrip []iTrip = new InternalTrip[internal];
        ExternalTrip []eTrip = new ExternalTrip[external];
        double sumInternal = 0, sumExternal = 0;
        for (int i = 0; i  < internal; i++)
        {
            iTrip[i] = new InternalTrip();
            System.out.println("Internal trip " + (int)(i + 1));
            iTrip[i].load();
            System.out.println("---------------------");
        }
        for (int i = 0; i < external; i++)
        {
            eTrip[i] = new ExternalTrip();
            System.out.println("External trip " + (int)(i + 1));
            eTrip[i].load();
            System.out.println("---------------------");
        }
        InternalTrip iTemp = new InternalTrip();
        ExternalTrip eTemp = new ExternalTrip();
        double maxITrip = -9999999, maxETrip = -99999999;
        for (int i = 0; i < internal; i++)
        {
            if (iTrip[i].getCost() >= maxITrip)
            {
                maxITrip = iTrip[i].getCost();
                iTemp = iTrip[i];
            }
            sumInternal += iTrip[i].getCost();
        }
        for (int i = 0; i < external; i++)
        {
            if (eTrip[i].getCost() >= maxETrip)
            {
                maxETrip = eTrip[i].getCost();
                eTemp = eTrip[i];
            }
            sumExternal += eTrip[i].getCost();
        }
        System.out.println("Total cost of Internal trips: " + sumInternal);
        System.out.println("Total cost of External trips: " + sumExternal);
        System.out.println("---------------------");
        System.out.println("Trip has max cost of Internal trip: ");
        iTemp.unload();
        System.out.println("---------------------");
        System.out.println("Trip has max cost of External trip: ");
        eTemp.unload();
    }
}
interface ITravel
{
    void load();
    void unload();
}

abstract class Travel implements ITravel
{
    protected int id;
    protected String driverName;
    protected int vehicleNumber;
    protected double productMass;
    protected double cost;
    int getID() {return id;}
    String getDriverName() {return driverName;}
    int getVehicleNumber() {return vehicleNumber;}
    double getProductMass() {return productMass;}
    double getCost() {return cost;}
    public void load()
    {
        Scanner in = new Scanner(System.in);
        Scanner inTmp = new Scanner(System.in);
        System.out.print("Enter ID of trip: ");
        id = in.nextInt();
        System.out.print("Enter name of driver: ");
        driverName = inTmp.nextLine();
        System.out.print("Enter number of vehicle: ");
        vehicleNumber = in.nextInt();
        System.out.print("Enter product mass: ");
        productMass = in.nextDouble();
        System.out.print("Enter trip's cost: ");
        cost = in.nextDouble();
    }
    public void unload()
    {
        System.out.println("ID of trip: " + getID());
        System.out.println("Driver's name: " + getDriverName());
        System.out.println("Number of vehicle: " + getVehicleNumber());
        System.out.println("Product mass: " + getProductMass());
        System.out.println("Trips' cost: " + getCost());
    }
}
class InternalTrip extends Travel
{
    protected int distance;
    int getDistance() {return distance;}
    public void load()
    {
        Scanner in = new Scanner(System.in);
        super.load();
        System.out.print("Enter distance of trip: ");
        distance = in.nextInt();
    }   
    public void unload()
    {
        super.unload();
        System.out.println("Distance of trip: " + getDistance());
    }
}
class ExternalTrip extends Travel
{
    protected String address;
    protected int numberOfDeliDay;
    String getAddress() {return address;}
    int getNumberOfDeliDay() {return numberOfDeliDay;}
    public void load()
    {
        Scanner in = new Scanner(System.in);
        Scanner inTmp = new Scanner(System.in);
        super.load();
        System.out.print("Enter address to delivery: ");
        address = inTmp.nextLine();
        System.out.print("Enter number of days to delivery: ");
        numberOfDeliDay = in.nextInt();
    }
    public void unload()
    {
        super.unload();
        System.out.println("Address: " + getAddress());
        System.out.println("Number of days to delivery: " + getNumberOfDeliDay());
    }
}