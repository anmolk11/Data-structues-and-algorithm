#include<bits/stdc++.h>
using namespace std;

int binary__search_left(int A[],int N,int x){
    int i = -1,j = N;
    while(i + 1 < j){
        int m = i + (j - i)/2;
        if(A[m] <= x) i = m;
        else j = m; 
    }
    return i;
}

int main(){
    int N,k;

    cin>>N>>k;

    int A[N]; 

    for(int i = 0;i < N;i++){
        cin>>A[i];
    }   
    
    while(k--){
        int x;
        cin>>x;
        cout<<binary__search_left(A,N,x)<<"\n";
    }
}