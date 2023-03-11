#include <bits/stdc++.h>
using namespace std;

string encode(string A)
{
    string Ans;
    int i = 0, N = A.length();
    while (i < N)
    {
        char x = A[i];
        int c = 0;
        while (i < N && A[i] == x)
        {
            i++;
            c++;
        }
        string X = x + to_string(c); // to_string is used to convert any integer number into string
        Ans += X;
    }
    return Ans;
}
