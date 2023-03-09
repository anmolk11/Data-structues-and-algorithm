#include<iostream>
using namespace std;

int main(){
    // taking integer input
    int x;
    cin>>x;
    if(x % 2 == 0){
        cout<<x<<" is even";
    }
    else{
        cout<<x<<" is odd";
    }

    // taking float input 
    float f;
    cin>>f;

    cout<<f<<" x 2 = "<<2 * f;

    // taking character input
    char c;
    cin>>c;
    cout<<"The character you entered is "<<c;

    //taking string input
    string first_name,last_name;
    cout<<"Enter your name : ";
    cin>>first_name>>last_name;
    cout<<"Hello "<<first_name<<" "<<last_name<<" Welcome to NIT-w";

    // taking string input with multiple words
    string name;
    getline(cin,name);
    cout<<"Hello "<<name<<" Welcome to this course";

    // taking diff types of input in a single line
    string stud_name;
    float cgpa;
    cin>>stud_name>>cgpa;
    cout<<"Hello "<<stud_name<<" your CGPA is "<<cgpa;
}