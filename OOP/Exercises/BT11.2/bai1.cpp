#include<iostream>
using namespace std;
class Book
{
private:
    string name;
    string soSx;
public:
    Book() {}
    virtual void input()
    {
        cout << "Enter name of book: ";
        cin >> name;
        cout << "Enter production number: ";
        cin >> soSx;
    }
    virtual void display()
    {
        cout << "Name of book: " << name;
        cout << "\nProduction number: " << soSx;
    }
};
class SGK : public Book
{
private:
    string nameOfSub;
public:
    SGK() {}
    void input()
    {
        cout << "Enter name of subject: ";
        cin >> nameOfSub;
        Book::input();
    }
    void display()
    {
        cout << "Name of subject: " << nameOfSub;
        cout << "\n";
        Book::display();
    }
};
class Novel : public Book
{
private:
    string nameOfNol;
public:
    Novel() {}
    void input()
    {
        cout << "Enter name of subject: ";
        cin >> nameOfNol;
        Book::input();
    }
    void display()
    {
        cout << "Name of subject: " << nameOfNol;
        cout << "\n";
        Book::display();
    }
};
class Magazine : public Book
{
private:
    string nameOfMag;
public:
    Magazine() {}
    void input()
    {
        cout << "Enter name of subject: ";
        cin >> nameOfMag;
        Book::input();
    }
    void display()
    {
        cout << "Name of subject: " << nameOfMag;
        cout << "\n";
        Book::display();
    }
};