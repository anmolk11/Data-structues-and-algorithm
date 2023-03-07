#include<bits/stdc++.h>
using namespace std;
int main(){
    // ------------------------ Arithmetic operators -------------------------
    int A = 6;
    int B = 3;
    
    int sum = A + B; // 9
    cout<<sum;
    
    int sub = A - B; // 3
    cout<<sub;

    int mul = A * B; // 18
    cout<<mul;
    
    int div = A / B; // 2
    cout<<div;

    // gives the reminder when A is divided by B
    int mod = A % B; // 0
    cout<<mod;

    // ------------------------ Logical operators -------------------------
    bool isAbove6ft = true;
    bool haveClearedTheExam = true;
    
    if (isAbove6ft && haveClearedTheExam){
        // both condition satisfied
    }
    if (isAbove6ft || haveClearedTheExam){
        // any one of the condition satisfied.
    }
    if(!isAbove6ft){
        // is not above 6 ft.
    }

    // ------------------------ Comparison operators -------------------------
    int raviAge = 19;
    int rajuAge = 21;
    
    if (raviAge == rajuAge){
        // ravi and raju are of same age.
    }
    if (raviAge != rajuAge){
        // ravi and raju are not of same age.
    }
    if (raviAge > rajuAge){
        // ravi’s age is greater then raju.
    }
    if (raviAge < rajuAge){
        // ravi’s age is lesser then raju.
    }
    if (raviAge >= rajuAge){
        // ravi’s age is greater or equal to raju.
    }
    if (raviAge <= rajuAge){
        // ravi’s age is lesser or equal to raju.
    }
}