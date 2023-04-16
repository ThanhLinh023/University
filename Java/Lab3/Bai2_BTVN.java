import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Map.Entry;

public class Bai2_BTVN {
    public static void main(String[] args)
    {
        HashMap<String, String> contact = new HashMap<String, String>();
        contact.put("0122435823", "HCM City");
        contact.put("0123246823", "Binh Duong");
        contact.put("0932435823", "London");
        contact.put("0983425823", "USA");
        contact.put("0823415823", "Canada");
        contact.put("0873415823", "Canada");
        contact.put("0312535823", "Texas");
        Scanner in = new Scanner(System.in);
        System.out.print("Enter phone to find information (10 numbers): ");
        String phone = in.nextLine();
        if (contact.get(phone) != null) 
        {
            System.out.println("Registered number of " + phone + " is at " + contact.get(phone));
        }
        else
        {
            System.out.println("No registered information");
        }
        System.out.print("Enter address: ");
        String addrr = in.nextLine();
        System.out.println("Registered numbers at " + addrr + " is:");
        for (Entry<String, String> entry : contact.entrySet()) 
        {
            if (entry.getValue().equals(addrr)) 
            {
                System.out.println(entry.getKey());
            }
        }
    }
}