#include<bits/stdc++.h>
using namespace std;

int binary__search_right(int A[],int N,int x){
    int i = -1,j = N;
    while(i + 1 < j){
        int m = i + (j - i)/2;
        if(A[m] >= x) j = m;
        else i = m; 
    }
    return j;
}

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

    cin>>N;

    int A[N]; 

    for(int i = 0;i < N;i++){
        cin>>A[i];
    }   
    
    sort(A,A + N);

    cin>>k;

    while(k--){
        int x,y;
        cin>>x>>y;
        int right = binary__search_right(A,N,x);
        int left = binary__search_left(A,N,y);
        cout<<left - right + 1<<"\n";
    }
}