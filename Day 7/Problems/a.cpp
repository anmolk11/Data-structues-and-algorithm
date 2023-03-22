#include<bits/stdc++.h>
using namespace std;


int F(string A){
    int i = -1,j = A.length();

    while(i + 1 < j){
        int m = i + (j - i)/2;
        if(A[m] == '1') j = m;
        else i = m;
    }
    return j;
}


int main(){
    string A = "000000001";

    cout<<F(A);
}