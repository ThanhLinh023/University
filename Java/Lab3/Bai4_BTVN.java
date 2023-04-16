import java.util.*;

public class Bai4_BTVN {
    public static void main(String[] args)
    {
        createCardSet card = new createCardSet();
        card.shuffle();
    }
}
class Cards 
{
    private String value[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    private String property[] = {"Bich", "Chuon", "Ro", "Co"};
    public ArrayList<String> getCard()
    {
        ArrayList<String> list = new ArrayList<String>();
        for (int i = 0; i < value.length; i++)
        {
            for (int j = 0; j < property.length; j++)
            {
                String tmp = value[i] + property[j];
                list.add(tmp);
            }
        }
        return list;
    }
}
class createCardSet 
{
    public void shuffle()
    {
        Cards c = new Cards();
        ArrayList<String> list = new ArrayList<String>();
        list = c.getCard();
        Collections.shuffle(list, new Random());
        Object []arr = list.toArray();
        System.out.print("Group 1: ");
        for (int i = 0; i < 13; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\nGroup 2: ");
        for (int i = 13; i < 26; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\nGroup 3: ");
        for (int i = 26; i < 39; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.print("\nGroup 4: ");
        for (int i = 39; i < 52; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }
}