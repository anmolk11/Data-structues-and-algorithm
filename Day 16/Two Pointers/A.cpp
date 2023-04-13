#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;

    int A[N],B[M];

    for(int i = 0;i < N;i++) cin>>A[i];
    for(int i = 0;i < M;i++) cin>>B[i];

    int C[N + M];


    int i = 0,j = 0,k = 0;

    while(i < N and j < M){
        if(A[i] < B[j]){
            C[k] = A[i];
            i++;
        }
        else{
            C[k] = B[j];
            j++;
        }
        k++;
    }


    while(i < N){
        C[k++] = A[i++];
    }

    while(j < M){
        C[k++] = B[j++];
    }

    for(int i = 0;i < N + M;i++) cout<<C[i]<<' ';
}