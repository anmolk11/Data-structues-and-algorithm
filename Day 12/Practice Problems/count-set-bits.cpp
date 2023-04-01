// Program to count number of set bits (i.e bits that are 1)
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    // Naive Solution - Time : O(Total Bits in n)
    // int count{0};
    // while(n) {
    //     count = count + (n&1);
    //     n = n >> 1;
    // }
    // cout << count << endl;


    // Brain Kerningan's Algoright - Time : O(no. of set bits)
    // int count{0};
    // while(n) {
    //     n = (n&(n-1));
    //     count++;
    // }
    // cout << count << endl;

    // Look Up table method - Time : O(1), preassuming we did some precompuation
    int table[256];
    table[0] = 0;
    for(int i = 1; i < 256; i++) {
        table[i] = (i&1) + table[i/2];
    }
    int count = 0;
    count += table[n & 0xff];
    n = n >> 8;
    count += table[n & 0xff];
    n = n >> 8;
    count += table[n & 0xff];
    n = n >> 8;
    count += table[n & 0xff];
    n = n >> 8;
    cout << count << endl;

    // Approach - , Time : O(Total Bits in n)
    // int map = 1;
    // int count{0};
    // for(int i = 0; i < 32; i++) {
    //     if((n&map)) {
    //         count++;
    //     }
    //     map = map << 1;
    // }
    // cout << count << endl;

    return 0;
}