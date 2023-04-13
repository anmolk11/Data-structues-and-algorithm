#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    int A[N],B[M];

    for(int i = 0;i < N;i++) cin>>A[i];
    for(int i = 0;i < M;i++) cin>>B[i];

    int i = 0,j = 0;

    for(int j = 0; j < M;j++){
        while(i < N and A[i] < B[j]) i++;
        cout<<i<<' ';
    }
}