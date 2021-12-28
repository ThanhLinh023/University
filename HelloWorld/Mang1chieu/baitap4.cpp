#include<iostream>
using namespace std;
int dele(int a[], int &n, int k)
{
	if(k < 0 || k >= n)
	{
		return 0;
	}
	for(int i = k; i < n - 1; i++)
    {
		a[i] = a[i+1];
	}
	n--;
	return 1;
}
int main()
{
    int n, k, a[100];
    cout << "Nhap n : ";
    cin >> n;
    cout << "Nhap vao mang : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Nhap vao chi so k : ";
    cin >> k;
    dele(a, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}