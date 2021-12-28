#include<iostream>
using namespace std;
int main()
{
   int n, count (0);
   cout << "Nhap vao n : ";
   cin >> n;
   if (n > 0)
   {
       while (n > 10)
       {
           n /= 10;
           count++;
       }
       cout << "So luong chu so la : " << count + 1;
   }
   else
   {
       cout << "Nhap lai n";
   }
   return 0;
}