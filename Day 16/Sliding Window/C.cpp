#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long S;

    cin>>N>>S;

    long long sum = 0;

    int A[N];
    for(int i = 0;i < N;i++) cin>>A[i];


    int i = 0;
    long long Ans = 0;

    for(int j = 0;j < N;j++){
        sum += 0ll + A[j];
        while(sum > S){
            sum -= A[i];
            i++;
        }
        Ans += 0ll + (j - i + 1);
    }
    cout<<Ans;
}