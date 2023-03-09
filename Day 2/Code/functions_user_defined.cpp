#include<bits/stdc++.h>
using namespace std;

long long factorial(int x){
    long long f = 1;
    for(long long i = 1;i <= x;i++){
        f = f * i;
    }
    return f;
}

long long combination(int n,int r){
    //  nCr = n! / (r! * (n-r)!)
    return factorial(n)/(factorial(r) * (factorial(n - r)));
}


// function that returns nothing
void welcomeMe(string name){
    cout<<"Hello "<<name<<" Welcome to NIT-W\n";
}

int main(){
    int x;
    cout<<"Enter a number : ";
    cin>>x;
    cout<<"Factorial of "<<x<<" is = "<<factorial(x)<<"\n";
    for(int x = 1;x <= 20;x++){
        cout<<"Factorial of "<<x<<" is = "<<factorial(x)<<"\n";
    }
    
    string name;
    cout<<"What is your name? ";
    cin>>name;
    welcomeMe(name);
}