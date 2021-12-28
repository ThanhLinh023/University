#include<iostream>
using namespace std;
void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
	int n, a[n], max(0), pos (-1);
	cin >> n;
	input(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			pos = i;
			max = a[i];
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0 && a[i] > max)
		{
			pos = i;
			max = a[i];
		}
	}
	cout << pos;
	return 0;
}