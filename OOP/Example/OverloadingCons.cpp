#include<iostream>
using namespace std;
class Student
{    
    private:
        string name;
        char gender;
    public:
        Student()
        {
            name = "Unknown";
            gender = 'u';
        }
        Student(string ht)
        {
            name = ht;
            this->gender = 'u';
        }
        Student(char gt)
        {
            this->name = "Unknown";
            gender = gt;
        }
        Student(string ht, char gt)
        {
            name = ht;
            gender = gt;
        }
        void display()
        {
            cout << "Name: " << name << endl;
            cout << "Gender: ";
            if (gender == 'u') cout << "Unknown\n";
            if (gender == 'f') cout << "Female\n";
            if (gender == 'm') cout << "Male\n";
        }
};
int main() 
{
	Student s1;
	s1.display();
	Student s2("Quang");
	s2.display();
	Student s3('m');
	s3.display();
	Student s4("Thu", 'f');
	s4.display();
	return 0;
}