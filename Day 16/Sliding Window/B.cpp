#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long S;

    cin>>N>>S;

    long long sum = 0;

    int A[N];
    for(int i = 0;i < N;i++) cin>>A[i];


    int i = 0,Ans = N + 1;

    for(int j = 0;j < N;j++){
        sum += 0ll + A[j];
        while(sum - A[i] >= S){
            sum -= A[i];
            i++;
        }
        if(sum >= S) Ans = min(Ans,j - i + 1);
    }
    if(Ans == N + 1) cout<<-1;
    else cout<<Ans;
}