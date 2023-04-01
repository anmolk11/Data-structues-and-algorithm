// This is variation of "odd occurance number" question.
// Given an array of n numbers that has values in range
// [1.....n+1]. Every no. appear exactly once. Hence one number is missing
// We have to find that missing number.
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
    for(int i = 1; i <= n+1; i++) {
        res ^= i;
    }
    cout << res << endl;
    return 0;
}