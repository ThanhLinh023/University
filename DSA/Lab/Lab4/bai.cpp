#include<iostream>
#include<ctime>
#include<cstdlib>
#include <time.h>
#define max 1000000
using namespace std;
void swap(float &x, float &y)
{
    float temp = x;
    x = y;
    y = temp;
}
void createA(float *a, int n)
{
    cout << "Nhap phan tu thu cong: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void createAuto(float *a)
{
    for (int i = 0; i < 100000; i++)
    {
        float t = rand() * 1.000 + ((rand() % 1000) * 1.000) / 1000;
        a[i] = t;
    }
}
void createAuto2(float *a)
{
    for (int i = 0; i < 100000; i++)
    {
        float t = rand() * 4.000 + ((rand() % 1000) * 1.000) / 1000;
        a[i] = t;
    }
}
void printArr(float *a)
{
    for (int i = 0; i < 100000; i++)
    {
        cout << a[i] << " ";
    }
}
void selectionSort(float *a)
{
    int min;
    for (int i = 0; i < 100000 - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < 100000; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
void insertionSort(float *a)
{
    for (int i = 1; i < 100000; i++)
    {
        float e = a[i];
        int k;
        for (k = i - 1; k > -1; k--)
        {
            if (a[k] < e) break;
            a[k + 1] = a[k];
        }
        a[k+1] = e;
    }
}
double timeSelection(float *a)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    selectionSort(a);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
double timeInsertion(float *a)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    insertionSort(a);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
int main()
{
    float *a = new float[max];
    int k;
    cout << "------------------MENU----------------\n";
    cout << "1. Tao mang bang phuong phap thu cong\n";
    cout << "2. Tao mang tu dong\n";
    cout << "3. Tao mang tu dong trong khoang [39000; 99000]\n";
    cout << "4. Xuat mang\n";
    cout << "5. Sap xep bang chon truc tiep\n";
    cout << "6. Tinh thoi gian sap xep bang chon truc tiep\n";
    cout << "7. Sap xep bang chen truc tiep\n";
    cout << "8. Tinh thoi gian sap xep bang chen truc tiep\n";
    cout << "9. So sanh thoi gian 2 thuat toan tren cung 1 bo du lieu\n";
    cout << "------------------END----------------\n";
    while (1)
    {
        cout << "\tChon lua chon: ";
        cin >> k;
        switch (k)
        {
            case 1:
            {
                int n;
                cout << "Nhap so phan tu: ";
                cin >> n;
                createA(a, n);
                cout << "\n--------------------------------\n";
                break;
            }
            case 2:
            {
                createAuto(a);
                cout << "Da tao xong mang tu dong";
                cout << "\n--------------------------------\n";
                break;
            }
            case 3:
            {
                createAuto2(a);
                cout << "Da tao mang tu dong trong khoang [39000; 99000]";
                cout << "\n--------------------------------\n";
                break;
            }
            case 4:
            {
                cout << "Mang da nhap: ";
                printArr(a);
                cout << "\n--------------------------------\n";
                break;
            }
            case 5:
            {
                selectionSort(a);
                cout << "Sap xep bang chon truc tiep: ";
                printArr(a);
                cout << "\n--------------------------------\n";
                break;
            }
            case 6:
            {
                cout << "Thoi gian sap xep chon truc tiep: " << timeSelection(a);
                cout << "\n--------------------------------\n";
                break;
            }
            case 7:
            {
                insertionSort(a);
                cout << "Sap xep bang chen truc tiep: ";
                printArr(a);
                cout << "\n--------------------------------\n";
                break;
            }
            case 8:
            {
                cout << "Thoi gian sap xep chen truc tiep: " << timeInsertion(a);
                cout << "\n--------------------------------\n";
                break;
            }
            case 9:
            {
                for (int i = 0; i < 15; i++)
                {
                    float *m1 = new float[max];
                    createAuto(m1);
                    cout << "\n---------------------------------------";
                    cout << "\nSo sanh lan thu: " << i + 1;
                    cout << "\nChon truc tiep\t\tChen truc tiep\n";
                    cout << timeSelection(m1) << "\t\t\t\t" << timeInsertion(m1);
                }
                cout << "\n---------------------------------------\n";
                break;
            }
        }
    }
    delete a;
    return 0;
}