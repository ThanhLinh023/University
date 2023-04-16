import java.util.InputMismatchException;
import java.util.Scanner;
public class Bai1_BTVN {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        Student st = new Student();
        try
        {
            System.out.print("Enter student's ID: ");
            long id = in.nextLong();
            st.setID(id);
            System.out.print("Enter student's name: ");
            String name = in.nextLine();
            st.setName(name);
            in.next();
            System.out.print("Enter student's marks: ");
            double marks = in.nextDouble();
            st.setMark(marks);
            st.ToString();
        }
        catch (InputMismatchException e)
        {
            System.out.println("ID or Mark must be number");
        }
        catch (Exception e)
        {
            System.out.println("Mark must be number in range 0 to 10");
        }
    }
}
class Student 
{
    private long studentID;
    private String studentName;
    private double mark;
    Student() {}
    void setID(long a){
        this.studentID = a;
    }
    void setName(String a) {this.studentName = a;}
    void setMark(double a) throws Exception {
        if (a < 0 || a > 10)
        {
            throw new Exception();
        }
        this.mark = a;
    }
    long getID() {return this.studentID;}
    String getName() {return this.studentName;}
    double getMark() {return this.mark;}
    public void ToString()
    {
        System.out.println("Student's ID: " + getID());
        System.out.println("Student's name: " + getName());
        System.out.println("Student's marks: " + getMark());
    }
}