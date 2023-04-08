import java.util.Scanner;

public class bai3_BTVN {
    public static void main(String[] args)
    {
        Student sv1 = new Student(1, "Jack", 5.5, 7.5);
        Student sv2 = new Student(2, "Michael", 4, 9);
        Student sv3 = new Student(3, "Elly", 9, 8.5);
        System.out.println("StudentID\tName\tTheoryMark\tPracticeMark\tAverageMark");
        sv1.ToString();
        sv2.ToString();
        sv3.ToString();
    }
}
class Student
{
    private int stuId;
    private String name;
    private double theory, practice;
    Student()
    {
        stuId = 0;
        name = "";
        theory = 0;
        practice = 0;
    }
    Student(int id, String name, double theory, double practice)
    {
        this.stuId = id;
        this.name = name;
        this.theory = theory;
        this.practice = practice;
    }
    void setID(int id) {stuId = id;}
    void setName(String s) {name = s;}
    void setTheory(double f) {theory = f;}
    void setPractice(double f) {practice = f;}
    int getID() {return stuId;}
    String getName() {return name;}
    double getTheory() {return theory;}
    double getPractice() {return practice;}
    double averagePoint()
    {
        return (double)(getTheory() * 0.5 + getPractice() * 0.5);
    }
    void ToString()
    {
        System.out.println(getID() + "\t\t" + getName() + "\t\t" + getTheory() + "\t\t" + getPractice() + "\t\t" + averagePoint());
    }
}