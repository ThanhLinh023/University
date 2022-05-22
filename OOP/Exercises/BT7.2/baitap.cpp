#include<iostream>
using namespace std;
class Matrix;
class Vector
{
private:
    double *cord;
    int n;
public:
    Vector() 
    {
        cord = new double[n];
    }
    Vector(int n, double x) {}
    Vector(const Vector &a) {}
    ~Vector() 
    {
        delete cord;
    }
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;
        cord = new double[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> cord[i];
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << cord[i] << " ";
        }
    }
    int add(const Vector &a)
    {
        Vector t;
        if (n == a.n)
        {
            for (int i = 0; i < n; i++)
            {
                t.cord[i] = cord[i] + a.cord[i];
            }
            cout << "After adding: ";
            t.display();
            return 1;
        }
        else
        {
            cout << "\nCannot add.";
        }
    }
    void mul(const double &k)
    {
        Vector t;
        for (int i = 0; i < n; i++)
        {
            t.cord[i] = k * cord[i];
        }
        cout << "Vector after multiplying with " << k << " : ";
        t.display();
    }
    int sub(const Vector &a)
    {
        if (n == a.n)
        {
            Vector t;
            for (int i = 0; i < n; i++)
            {
                t.cord[i] = cord[i] - a.cord[i];
            }
            cout << "After subtracting: ";
            t.display();
            return 1;
        }
        return 0;
    }
    double scalar(const Vector &a)
    {
        double t(0.0);
        if (n == a.n)
        {
            for (int i = 0; i < n; i++)
            {
                t += (cord[i] * a.cord[i]);
            }
        }
        return t;
    }
    friend Vector mul(const Matrix &a, const Vector &b) {}
};
class Matrix
{
private:
    int m;
    int n;
    double **element;
public:
    Matrix() {}
    Matrix(const Matrix &a) {}
    ~Matrix()
    {
        for (int i = 0; i < m; i++)
        {
            delete[] element[i];
        }
        delete[] element;
    }
    void input()
    {
        cout << "Enter number of row: ";
        cin >> m;
        cout << "Enter number of columns: ";
        cin >> n;
        element = new double*[m];
        for (int i = 0; i < m; i++)
        {
            element[i] = new double[n];
        }
        cout << "Enter matrix: ";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> element[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << element[i][j] << " ";
            }
            cout << endl;
        }
    }
    int getM() {return m;}
    int add(const Matrix &a)
    {
        Matrix t;
        if (m == a.m && n == a.n)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    t.element[i][j] = element[i][j] + a.element[i][j];
                }
            }
            cout << "Matrix after adding: ";
            t.display();
            return 1;
        }
        else
        {
            cout << "\nCannot add.";
        }
    }
    void mulK(const double &k)
    {
        Matrix t;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                t.element[i][j] += (k * element[i][j]);
            }
        }
        cout << "Matrix after multiplying with " << k << " : ";
        t.display();
    }
    int mul(const Matrix &a)
    {
        Matrix t;
        if (n == a.m)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < a.n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        t.element[i][j] += (element[i][k] * a.element[k][j]);
                    }
                }
            }
            cout << "Result: ";
            t.display();
            return 1;
        }
        else
        {
            cout << "\nCannot multiply.";
        }
    }
    friend Vector multiply(const Matrix &a, const Vector &b) {}
};