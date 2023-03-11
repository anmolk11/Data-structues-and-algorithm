#include <bits/stdc++.h>
using namespace std;

// log10(x) + 1 can be used to find the number of digits in a number
int findNumbers(int A[],int N)
{
    int Ans = 0;
    for (int i = 0;i < N;i++)
    {
        // log10(x) + 1 = N
        // N - 1 = log10(x)
        // if log10(x) is odd, then N is even
        // for odd number X % 2 == 1 

        Ans += (int(log10(A[i])) % 2);

        // converting into int because log10() will return in float
    }
    return Ans;
}

// another way
int findNumbers(int A[],int N){
    int Ans = 0;

    for(int i = 0;i < N;i++){
        int count = 0;
        while(A[i] > 0){
            count++;
            A[i] = A[i] / 10;
        }
        if(count % 2 == 0) ++Ans;
    }

    return Ans;
}
