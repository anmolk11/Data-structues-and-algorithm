// Calculate square of a number without using *, / and pow()
// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
#include <iostream>
using namespace std;

int square(int n) {
    if(n == 0)
        return 0;
    int x = n >> 1;
    if(n & 1) 
        return (square(x) << 2) + (x << 2) + 1;
    else
        return (square(x) << 2);
}
int main() {
    int n;
    cin >> n;
    cout << "n^2 : " << square(n) << endl;
    return 0;
}