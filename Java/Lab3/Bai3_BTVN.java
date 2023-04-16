import java.util.ArrayList;
import java.util.*;
import java.util.Map.Entry;
public class Bai3_BTVN {
    public static void main(String[] args)
    {
        ArrayList<String> arr = new ArrayList<String>();
        arr.add("Michael");
        arr.add("John");
        arr.add("Tim");
        arr.add("Tom");
        arr.add("Jenny");
        arr.add("Bob");
        arr.add("Lucas");
        arr.add("Young");
        arr.add("Jenny");
        arr.add("Bob");
        arr.add("Lucas");
        arr.add("Young");
        arr.add("Mike");
        arr.add("Tom");
        arr.add("Lucas");
        System.out.println("Staff receives gift: " + chosenStaff(arr));
        System.out.println("List of products base on staff's name: " + productName(arr));
        System.out.println("New product name: " + mostPopularName(arr));
    }
    public static String chosenStaff(ArrayList<String> a)
    {
        int index = (int)(Math.random() * a.size());
        return a.get(index);
    }
    public static Set<String> productName(ArrayList<String> a)
    {
        Set<String> result = new HashSet<String>();
        for (String i : a)
        {
            result.add(i);
        }
        return result;
    }
    public static String mostPopularName(ArrayList<String> a)
    {
        HashMap<String, Integer> result = new HashMap<String, Integer>();
        int count;
        for (String i : a)
        {
            count = 0;
            if (result.containsKey(i) == false)
            {
                for (String j : a)
                {
                    if (i == j) count++;
                }
                result.put(i, count);
            }
            else continue;
        }
        int max = -9999999;
        String tmp = "";
        for (Entry<String, Integer> entry : result.entrySet())
        {
            if (entry.getValue() > max)
            {
                max = entry.getValue();
                tmp = entry.getKey();
            }
        }
        return tmp;
    }
}
