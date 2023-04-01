// Prgram to find that one odd occuring number in an array where all other numbers are occuring 
// even number of times
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    int res{0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        res ^= arr[i];
    } 
    cout << res << endl;
    return 0;
}