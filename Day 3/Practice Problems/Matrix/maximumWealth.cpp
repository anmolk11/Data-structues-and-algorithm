#include <bits/stdc++.h>
using namespace std;
int maximumWealth(int A[][100],int n,int m)
{
    int Ans = 0;
    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = 0;j < m;j++){
            sum = sum + A[i][j];
        }
        Ans = max(Ans,sum);
    }
    return Ans;
}