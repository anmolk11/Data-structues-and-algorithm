#include<bits/stdc++.h>
using namespace std;
int main(){
    // // power
    int x,y;
    cout<<"Enter x and y : ";
    cin>>x>>y;
    int answer = pow(x,y); // x^y i.e. x to the power y
    cout<<"x to the power y : "<<answer<<"\n";

    // square root
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    float answer = sqrt(n);
    cout<<"sqrt of "<<n << " is " <<answer<<"\n";

    // maximum and minimum
    int a,b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    cout<<"The maximum of these are : "<<max(a,b)<<"\n";
    cout<<"The minimum of these are : "<<min(a,b)<<"\n";

    // finding max or min of more then two numbers
    cout<<max({1,2,3,4,44,66})<<"\n";
    cout<<min({1,2,3,4,44,66})<<"\n";

    // absoulute value
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    cout<<"Absolute value of "<<num<<" is  : "<<abs(num);
}