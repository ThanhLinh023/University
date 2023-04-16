import java.util.Scanner;
import java.util.TreeMap;
import java.util.*;

public class Bai5_BTVN {
    public static void main(String[] args)
    {
        Dictionary dict = new Dictionary();
        dict.initialize();
        int choose;
        Scanner in = new Scanner(System.in);
        while (true)
        {
            System.out.println("Choose action\n1.Add word to dictionary.\n2.Find word.\n3.Exit");
            choose = in.nextInt();
            if (choose == 1)
            {
                dict.addWord();
            }
            else if (choose == 2)
            {
                dict.findWord();
            }
            else 
            {
                break;
            }
            System.out.println("---------------------------------");
        }
    }
}
class Words
{
    private String word;
    private String meaning;
    private String type;
    Words() {}
    Words(String word, String meaning, String type)
    {
        this.word = word;
        this.meaning = meaning;
        this.type = type;
    }
    public String showWord()
    {
        return this.word + "(" + this.type + ") : " + this.meaning;
    }
    String getWord() {return word;}
}
class sortRoll implements Comparator<Words> 
{
 
    public int compare(Words a, Words b)
    {
        return a.getWord().compareTo(b.getWord());
    }
}
class Dictionary
{
    TreeMap<Words, Integer> map = new TreeMap<Words, Integer>(new sortRoll());
    void initialize()
    {
        map.put(new Words("Apple", "Qua tao", "Noun"), 1);
        map.put(new Words("Pineapple", "Qua dua", "Noun"), 1);
        map.put(new Words("Watch", "Dong ho", "Noun"), 1);
        map.put(new Words("Watch", "Xem phim", "Verb"), 1);
        map.put(new Words("Go", "Di lai", "Verb"), 1);
        map.put(new Words("Ten", "So 10", "Noun"), 1);
        map.put(new Words("Conflict", "Xung dot", "Noun"), 1);
        map.put(new Words("Find", "Tim kiem", "Verb"), 1);
        map.put(new Words("Weekend", "Cuoi tuan", "Noun"), 1);
        map.put(new Words("March", "Thang 3", "Noun"), 1);
        map.put(new Words("Play", "Choi", "Verb"), 1);
    }
    void addWord()
    {
        Scanner in = new Scanner(System.in);
        String word, mean, type;
        System.out.print("Enter word: ");
        word = in.nextLine();
        boolean checkExist = false;
        for (Words i : map.keySet())
        {
            if (i.getWord().toLowerCase().equals(word.toLowerCase()))
            {
                checkExist = true;
                break;
            }
        }
        if (checkExist)
        {
            System.out.println("Word is in the dictionary. Enter another word.");
        }
        else
        {
            System.out.print("Enter meaning in Vietnamese: ");
            mean = in.nextLine();
            System.out.print("Enter type of word: ");
            type = in.nextLine();
            map.put(new Words(word, mean, type), 1);
        }
    }
    void findWord()
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter word want to find: ");
        String findWord = in.nextLine();
        boolean check = false;
        for (Words i : map.keySet())
        {
            if (i.getWord().toLowerCase().equals(findWord.toLowerCase()))
            {
                System.out.print("Found word: ");
                System.out.println(i.showWord());
                check = true;
                break;
            }
        }
        if (!check)
        {
            System.out.println("Cannot find word.");
        }
    }
}