import java.util.Scanner;

public class bai8_BTVN {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        XeMay xm = new XeMay();
        XeTai xt = new XeTai();
        double massAdd, massRemove, petro, distance;
        System.out.print("Nhap luong hang muon dua len xe: ");
        massAdd = in.nextDouble();
        xm.changeProduct(massAdd);
        xt.changeProduct(massAdd);
        System.out.print("Nhap luong hang muon dua xuong: ");
        massRemove = in.nextDouble();
        xm.changeProduct(-massRemove);
        xt.changeProduct(-massRemove);
        System.out.print("Them xang cho xe: ");
        petro = in.nextDouble();
        xm.addMetro(petro);
        xt.addMetro(petro);
        System.out.print("Nhap quang duong di: ");
        distance = in.nextDouble();
        xm.startRun(distance);
        xt.startRun(distance);
        xm.countPetro();
        xt.countPetro();
        if (xm.Fuel() > 0)
        {
            System.out.println("Xe may chua het xang, luong xang con lai la " + xm.Fuel() + " lit");
        }
        else
        {
            System.out.println("Xe may da het xang");
        }
        if (xt.Fuel() > 0)
        {
            System.out.println("Xe tai chua het xang, luong xang con lai la " + xt.Fuel() + " lit");
        }
        else
        {
            System.out.println("Xe tai da het xang");
        }
    }
}
abstract class IVehicle 
{
    private double productMass;
    private double petro;
    private double distance;
    void changeProduct(double mass) {
        productMass += mass;
    };
    void addMetro(double mass) {
        petro += mass;
    };
    void startRun(double dis) {
        distance += dis;
    };
    double Fuel() {
        return petro;
    };
    double getProductMass() {return productMass;}
    double distance() {return distance;}
    abstract void countPetro();
}
class XeMay extends IVehicle
{
    void countPetro()
    {
        if (distance() >= 100)
        {
            addMetro(-2);
        }
        addMetro(-getProductMass() / 100);
    }
}

class XeTai extends IVehicle
{
    void countPetro()
    {
        if (distance() >= 100)
        {
            addMetro(-20);
        }
        addMetro(-getProductMass() / 100);
    }
}