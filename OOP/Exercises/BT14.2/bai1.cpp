#include <iostream>
using namespace std;
class Matrix
{
private:
    int row, col;
    int **data;
public:
    Matrix() 
    {
        row = col = 0;
    }
    Matrix(int x, int y)
    {
        row = x;
        col = y;
        data = new int *[row];
        for (int i = 0; i < row; i++)
        {
            data[i] = new int[col];
        }
    }
    void setAt(int i, int j, int x)
    {
        data[i][j] = x;
    }
    int getAt(int i, int j)
    {
        return data[i][j];
    }
    void input(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> data[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    friend Matrix operator+(const Matrix &a, const Matrix &b);
    friend Matrix operator-(const Matrix &a, const Matrix &b);
};
Matrix operator+(const Matrix &a, const Matrix &b)
{
    Matrix result(a.row, a.col);
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.col; j++)
        {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}
Matrix operator-(const Matrix &a, const Matrix &b)
{
    Matrix result(a.row, b.col);
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < b.col; j++)
        {
            for (int k = 0; k < a.col; k++)
            {
                result.data[i][j] += (a.data[i][k] * b.data[k][j]);
            }
        }
    }
    return result;
}
int main()
{
    int row1, col1, row2, col2;
    cout << "Nhap so dong ma tran thu nhat: ";
    cin >> row1;
    cout << "Nhap so cot ma tran thu nhat: ";
    cin >> col1;
    Matrix a(row1, col1);
    cout << "Nhap ma tran thu nhat:\n";
    a.input(row1, col1);
    cout << "Nhap so dong ma tran thu hai: ";
    cin >> row2;
    cout << "Nhap so cot ma tran thu hai: ";
    cin >> col2;
    Matrix b(row2, col2);
    cout << "Nhap ma tran thu hai:\n";
    b.input(row2, col2);
    Matrix c(row1, col1);
    Matrix d(row1, col2);
    c = a + b;
    d = a - b;
    cout << "Tong 2 ma tran\n";
    c.display();
    cout << "Tich 2 ma tran\n";
    d.display();
    return 0;
}