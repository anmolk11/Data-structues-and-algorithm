#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long S;

    cin>>N>>S;

    long long sum = 0,Ans = 0;

    int A[N];
    for(int i = 0;i < N;i++) cin>>A[i];


    int i = 0;

    for(int j = 0;j < N;j++){
        sum += 0ll + A[j];
        while(sum - A[i] >= S){
            sum -= A[i];
            i++;
        }
        if(sum >= S) Ans += 0ll + (i + 1);
    }
    
    cout<<Ans;
}