import java.util.Scanner;

public class bai4_BTVN {
    public static void main(String[] args)
    {
        Scanner inName = new Scanner(System.in);
        Scanner inType = new Scanner(System.in);
        Scanner inGia = new Scanner(System.in);
        Scanner inVolume = new Scanner(System.in);
        Xe []array = new Xe[100];
        int gia, dt;
        for (int i = 0; i < array.length; i++)
        {
            String name, type;
            System.out.print("Nhap ten chu xe " + (int)(i + 1) + ": ");
            name = inName.nextLine();
            if (name == "")
            {
                System.out.print("---------------\n");
                break;
            }
            System.out.print("Nhap ten loai xe: ");
            type = inType.nextLine();
            System.out.print("Nhap gia xe: ");
            gia = inGia.nextInt();
            System.out.print("Nhap dung tich cua xe: ");
            dt = inVolume.nextInt();
            array[i] = new Xe();
            array[i].setTenChuXe(name);
            array[i].setLoaiXe(type);
            array[i].setTriGia(gia);
            array[i].setDungTich(dt);
        }
        int i = 0;
        while (array[i] != null) 
        {
            array[i].detailTax();
            i++;
        }
        String nameFind, typeFind;
        Scanner find1 = new Scanner(System.in);
        Scanner find2 = new Scanner(System.in);
        System.out.print("Nhap vao ten chu xe muon tim: ");
        nameFind = find1.nextLine();
        System.out.print("Nhap vao ten loai xe muon tim: ");
        typeFind = find2.nextLine();
        float taxTmp = 0;
        int k = 0;
        while (array[k] != null) 
        {
            if (nameFind.equals(array[k].TenChuXe()))
            {
                if (typeFind.equals(array[k].LoaiXe()))
                {
                    taxTmp += array[k].Tax();
                    break;
                }
            }
            k++;
        }
        if (taxTmp != 0)
        {
            System.out.println("Thue phai dong: " + taxTmp);
        }
        else
        {
            System.out.println("Khong tim thay");
        }
    }
}

class Xe {
    private String tenChuXe;
    private String loaiXe;
    private int triGia;
    private int dungTich;
    private float tax;
    public void setTenChuXe(String tenChuXe) {this.tenChuXe = tenChuXe;}
    public void setLoaiXe(String loaiXe) {this.loaiXe = loaiXe;}
    public void setTriGia(int triGia) {this.triGia = triGia;}
    public void setDungTich(int dungTich) {this.dungTich = dungTich;}
    String TenChuXe() {return tenChuXe;}
    String LoaiXe() {return loaiXe;}
    int TriGia() {return triGia;}
    int DungTich() {return dungTich;}
    float Tax() {return tax;}
    void detailTax()
    {
        if (dungTich < 100)
        {
            tax += triGia * 1.01;
        }
        else if (dungTich >= 100 && dungTich <= 175)
        {
            tax += triGia * 1.03;
        }
        else
        {
            tax += triGia * 1.05;
        }
        System.out.println("Ten chu xe: " + tenChuXe);
        System.out.println("Loai xe: " + loaiXe);
        System.out.println("Tri gia xe: " + triGia);
        System.out.println("Dung tich: " + dungTich);
        System.out.println("Thue phai dong: " + tax);
        System.out.println("-------------------");
    }
}