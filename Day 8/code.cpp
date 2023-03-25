#include<bits/stdc++.h>
using namespace std;

void print_num(int N){
    if(N == 0) return;
    print_num(N - 1);
    cout<<N<<'\n';
}

int sum(int N){
    if(N == 0) return 0;

    return N + sum(N - 1);
}

void print_arr(int A[],int N,int i){
    if(i == N) return;
    print_arr(A,N,i + 1);
    cout<<A[i]<<' ';
}

int max_array(int A[],int N,int i){
    if(i == N) return INT_MIN;

    int max_from_rest = max_array(A,N,i + 1);

    return max(A[i],max_from_rest);
}


int min_array(int A[],int N,int i){
    if(i == N) return INT_MAX;

    int max_from_rest = min_array(A,N,i + 1);

    return min(A[i],max_from_rest);
}

int main(){
    // print_num(10);
    // cout<<sum(5);
    int A[] = {1,2,3,4,5};
    // print_arr(A,5,0);
    // cout<<max_array(A,5,0);
    // cout<<min_array(A,5,0);
}