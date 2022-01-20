#include<iostream>
#include<math.h>

using namespace std;

struct diem
{
    int hd;
    int td;
};

void input(diem &a)
{
    cout << "Nhap hoanh do : ";
    cin >> a.hd;
    cout << "Nhap tung do : ";
    cin >> a.td;
}
void output(diem a)
{
    cout << "Toa do diem vua nhap la : ";
    cout << "(" << a.hd << "; " << a.td << ")";
}

int main()
{
    int n;
    diem x, y, a[100];
    cout << "Nhap 2 diem bat ki.\n";
    input(x);
    output(x);
    cout << "\n";
    input(y);
    output(y);
    cout << "\n";
    cout << "Khoang cach giua 2 diem " << "(" << x.hd << "; " << x.td << ")" << " va " << "(" << y.hd << "; " << y.td << ")" << " la : ";
    cout << sqrt(abs((y.hd * y.hd + y.td * y.td) - (x.hd * x.hd + x.td * x.td))) << "\n";
    cout << "Nhap so luong diem : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].hd >> a[i].td;
    }
    cout << "Mang diem vua nhap la : ";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << a[i].hd << "; " << a[i].td << ")" << ", ";
    }
    cout << "\n";
    float distance[100] = {0};
    for (int i = 0; i < n; i++)
    {
        distance[i] += (sqrt((a[i].hd * a[i].hd) + (a[i].td * a[i].td)));
    }
    float max = distance[0], min = distance[0];
    diem m, k;
    for (int i = 0; i < n; i++)
    {
        if (distance[i] > max)
        {
            max = distance[i];
            m.hd = a[i].hd;
            m.td = a[i].td;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (distance[i] < min)
        {
            min = distance[i];
            k.hd = a[i].hd;
            k.td = a[i].td;
        }
    }
    cout << "Diem gan goc toa do nhat la : " << "(" << k.hd << "; " << k.td << ")\n";
    cout << "Diem xa goc toa do nhat la : " << "(" << m.hd << "; " << m.td << ")";
    return 0;
}