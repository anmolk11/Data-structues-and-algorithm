// Program to check if kth bit from right is set or not
#include <iostream>
using namespace std;
int main() {
    int n, k;
    cout << "(n >> k )" << endl;
    cin >> n >> k;
   
    // if( ( n & ( 1 << (k-1) ) ) ) {
    //     cout << "Yes" << endl;
    // }else {
    //     cout << "No" << endl;
    // }

    // Using right shift
    if(( ( n >> ( k - 1 ) ) & 1 )) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    return 0;
}