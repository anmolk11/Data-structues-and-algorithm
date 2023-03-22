#include<bits/stdc++.h>
using namespace std;


bool binary_search(int A[],int N,int target){
    int left = 0,right = N - 1;
    while(left <= right){
        int mid = left + (right - left)/2;

        if(A[mid] == target){
            return true;
        }
        else if(A[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return false;
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    
    int N = sizeof(A)/sizeof(A[0]);

    int target = 1;

    bool found = binary_search(A,N,target);

    if(found){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}