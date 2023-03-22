#include<bits/stdc++.h>
using namespace std;

bool linear_search(int A[],int N,int target){
    for(int i = 0;i < N;i++){
        if(A[i] == target){
            return true;
        }
    }
    return false;
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    
    int N = sizeof(A)/sizeof(A[0]);

    int target = 55;

    bool found = linear_search(A,N,target);

    if(found){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}