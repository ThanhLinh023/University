public class Sach
{
    private String MaSach;
    private String TenSach;
    private String TacGia;
    private String nxb;
    private double gia;
    Sach() {}
    Sach(String ms, String ts, String tg, String nxb, double gia)
    {
        this.MaSach = ms;
        this.TenSach = ts;
        this.TacGia = tg;
        this.nxb = nxb;
        this.gia = gia;
    }
    void setMaSach(String a) {this.MaSach = a;}  
    void setTenSach(String a) {this.TenSach = a;} 
    void setTacGia(String a) {this.TacGia = a;} 
    void setNXB(String a) {this.nxb = a;} 
    void setGia(double a) {this.gia = a;} 
    String getMaSach() {return this.MaSach;}
    String getTenSach() {return this.TenSach;}
    String getTacGia() {return this.TacGia;}
    String getNXB() {return this.nxb;}
    double getGia() {return this.gia;}
}
