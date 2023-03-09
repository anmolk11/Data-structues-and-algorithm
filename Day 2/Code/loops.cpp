#include<bits/stdc++.h>
using namespace std;
int main(){
    // while loop

    int count = 11;
    while(count <= 10){
        cout<<"Square of "<<count<<" is "<<count * count<<"\n";
        count++;
    }
    
    //Infinte loops

    string password = "secret";
    while (true) {
        string user_password;
        cout << "Enter your password: ";
        cin >> user_password;
        if (user_password == password) {
            cout << "Access granted." << endl;
            break;
        } 
        else {
            cout << "Incorrect password. Try again." << endl;
        }
    }

    // do while, will execute atleast once no matter what the condition is.
    do{
        cout<<"Square of "<<count<<" is "<<count * count<<"\n";
        count++;
    }while(count <= 10);

    // for loop
    for(int i = 1;i <= 10;i++){
        cout<<"Square of "<<i<<" is "<<i * i<<"\n";
    }
}