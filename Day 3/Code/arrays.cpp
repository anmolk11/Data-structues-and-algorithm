#include <iostream>
#include <array>
using namespace std;

void searching(int a[], int n)
{
    cout << "Size of array : " << n << endl;
    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Key found at index: " << i << endl;
            return;
        }
    }
    cout << "Key not found" << endl;
}

void out_of_bound()
{
    int a[5];
    a[1] = 1;
    cout << a[1] << endl;
    a[2] = 2;
    cout << a[2] << endl;
    a[3] = 3;
    cout << a[3] << endl;
    a[4] = 4;
    cout << a[4] << endl;
    a[5] = 5;
    cout << a[5] << endl;
    a[6] = 6;
    cout << a[6] << endl;
    a[7] = 7;
    cout << a[7] << endl;

    int b[1];
    for (int i = 0; i < 1000; i++)
    {
        cout << i << " ";
    }
}

int main()
{
    // Out of bound example
    // out_of_bound();

    int a[] = {10, 12, 14, 15, 6};

    // searching
    searching(a, 5);

    // cout << __cplusplus << endl;
    return 0;
}