// Divide two integers without using multiplication, division and mod operator
// https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
// Given a two integers say a and b. Find the quotient after dividing a by b without using multiplication, division and mod operator.
#include <iostream>
using namespace std;
int divideTwo(int,int);
int main() {
    int dividend_c, divisor_c;
    cin >> dividend_c >> divisor_c;
    // Navie Approach
    // int sign = 1;
    // if((a > 0 && b < 0) || (a < 0 && b > 0)) {
    //     sign = -1;
    // }
    // a = abs(a);
    // b = abs(b);
    // int ans = 0;
    // while (a >= b) {
    //     a -= b;
    //     ans++;
    // }
    // cout << ans*sign << endl;

    // Bit Manipulation
    int64_t result = divideTwo(dividend_c,divisor_c);
    cout << result << endl;
}
int divideTwo(int dividend_c, int divisor_c) {
    int check = (dividend_c < 0) ^ ( divisor_c < 0);
    int64_t dividend = dividend_c;
    int64_t divisor = divisor_c;
    dividend = abs(dividend);
    divisor = abs(divisor);
    int64_t result{0};
    while(divisor <= dividend) {
        int64_t quo = 1;
        int64_t temp = divisor;
        while(temp <= dividend) {
            temp <<= 1;
            quo <<= 1;
        }
        result += quo>>1;
        dividend -= temp>>1;
    }
    if(check) {
        return ~(result)+1;
    }else if (result > INT32_MAX) {
        return INT32_MAX;
    }else {
        return result;
    }
}