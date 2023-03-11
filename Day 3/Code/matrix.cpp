#include <iostream>
using namespace std;

void snake_pattern()
{
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the element at position " << i << " " << j << ": ";
            cin >> a[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << a[i][j] << " ";
            }
        }
    }

    // Time Complexity: O(n*m)
    cout << endl;
}

int main()
{
    int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Class Problem : Print snake pattern for a matrix
    snake_pattern();
    return 0;
}