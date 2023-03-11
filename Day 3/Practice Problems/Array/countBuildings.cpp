#include <bits/stdc++.h>
using namespace std;

int countBuildings(int A[], int N)
{
    int Ans = 0;

    int maxSoFar = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > maxSoFar)
        {
            ++Ans;
            maxSoFar = A[i];
        }
    }

    return Ans;
}
