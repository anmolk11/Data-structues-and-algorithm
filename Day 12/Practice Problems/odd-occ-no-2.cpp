// Prgram to find exactly 2 odd occuring number in an array where all other numbers are occuring 
// even number of times
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    int XOR{0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        XOR ^= arr[i];
    } 
    int LSB = XOR & ~(XOR-1);
    int res1{0},res2{0};
    for(int i = 0; i < n; i++) {
        if( (arr[i] & LSB) != 0) {
            res1 ^= arr[i];
        }else {
            res2 ^= arr[i];
        }
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}