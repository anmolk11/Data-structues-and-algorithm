#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    cout << "Enter the size of array : ";
    cin >> len;
    int A[len];
    cout<<"\nEnter array : \n";
    for (int i = 0; i < len; i++)
    {
        cin >> A[i];
    }
    cout << "Enter dimension of 2D array : ";

    int n, m;

    cin >> n >> m;

    if (len != n * m)
    {
        cout << "Not possible!";
        return 0;
    }

    int k = 0;

    int Ans[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Ans[i][j] = A[k++];
        }
    }

    cout << "\nConverted Array is : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << Ans[i][j] << ' ';
        }
        cout << '\n';
    }
}