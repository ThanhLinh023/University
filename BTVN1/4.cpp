#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;
    int g1, p1, giay1;
    int g2, p2, giay2;
    cout << "Nhap gio 1 : ";
    cin >> h1 >> m1 >> s1;
    cout << "Nhap gio 2 : ";
    cin >> h2 >> m2 >> s2;
    g1 = h1 + h2 + ( m1 + m2 + (s1 + s2) / 60 ) / 60;
    p1 = ( m1 + m2 + (s1 + s2) / 60 ) % 60;
    giay1 = (s1 + s2) % 60;
    g2 = abs(h1 - h2 - ( m1 - m2 + (s1 - s2) / 60 ) / 60);
    p2 = abs(( m1 - m2 + (s1 - s2) / 60 ) % 60);
    giay2 = abs((s1 - s2) % 60);
    cout << "Tong 2 gio nay la : " << g1 << ":" << p1 << ":" << giay1 << endl;
    cout << "Hieu 2 gio nay la : " << g2 << ":" << p2 << ":" << giay2;
    return 0;    
}   