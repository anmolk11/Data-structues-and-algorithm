#include <bits/stdc++.h>
using namespace std;

// taking extra memory
string reverse_extra(string A)
{
    int len = A.length();

    string Ans;

    for (int i = len - 1; i >= 0; i--)
    {
        Ans.push_back(A[i]);
    }

    return Ans;
}

// doing it inplace, i.e. without taking extra memory
string reverse_inplace(string A)
{
    int i = 0, j = A.length() - 1;
    while (i < j)
    {
        swap(A[i], A[j]);
        i++;
        j--;
    }
    return A;
}
