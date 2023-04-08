import java.util.Scanner;
public class bai5_BTVN {
    public static void main(String[] args)
    {
        Employee p1 = new Employee();
        Scanner in = new Scanner(System.in);
        String name;
        int age, salary;
        float rate;
        System.out.print("Enter name: ");
        name = in.nextLine();
        p1.setName(name);
        System.out.print("Enter age: ");
        age = in.nextInt();
        p1.setAge(age);
        System.out.print("Enter salary: ");
        salary = in.nextInt();
        p1.setSalary(salary);
        p1.show();
        System.out.print("Enter salary increasing rate: ");
        rate = in.nextFloat();
        System.out.print("Salary after increasing by rate " + rate + " : " + p1.addSalary(rate));
    }
}
interface IPeople
{
    void show();
}
abstract class People implements IPeople
{
    private String name;
    private int age;
    People() {}
    public void setName(String name) {this.name = name;}
    public void setAge(int age) {this.age = age;}
    public String getName() {return name;}
    public int getAge() {return age;}
}
class Employee extends People
{
    private int salary;
    public void setSalary(int salary) {this.salary = salary;}
    public int getSalary() {return salary;}
    public double addSalary() {
        int sal = getSalary();
        return sal * 1.1;
    }
    public double addSalary(float rate) {
        int sal = getSalary();
        return sal * (1 + rate);
    }
    public void show() {
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Salary: " + getSalary());
        System.out.println("Salary after increasing 10%: " + addSalary());
    }
}