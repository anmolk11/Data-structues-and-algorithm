// Program to check if given number is power of two or not, ex 0,1,2,4,8,16,32......
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // int map = (1 << (int)log2(n));
    // if((n&map) == n && n != 0) {
    //     cout << "Yes" << endl;
    // }else {
    //     cout << "No" << endl;
    // }
    if(n != 0 && (n & (n-1)) == 0) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}