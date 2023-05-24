
import java.util.ArrayList;

public class DSSach
{
    ArrayList<Sach> list = new ArrayList<Sach>();
    public void themSach(String ms, String ts, String tg, String nxb, double gia)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list.get(i).getMaSach().equals(ms))
            {
                break;
            }
            else
            {
                list.add(new Sach(ms, ts, tg, nxb, gia));
                break;
            }
        }
    }
    public Sach ttSachViTri(int i)
    {
        return list.get(i);
    }
    public void xoaSach(String ms)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list.get(i).getMaSach().equals(ms))
            {
                list.remove(i);
                break;
            }
        }
    }
    public Sach timSach(String ms)
    {
        Sach a = new Sach();
        for (int i = 0; i < list.size(); i++)
        {
            if (list.get(i).getMaSach().equals(ms))
            {
                a = list.get(i);
            }
        }
        return a;
    }
    public void capNhatSach(String ms)
    {
        
    }
    public int tongSoSach() {return list.size();}
}