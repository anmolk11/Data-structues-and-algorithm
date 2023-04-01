// This code if to generate power set from given set
// Input of set is given as string of lowercase alphabets
#include<iostream>
#include<math.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    string *result = new string[(int)pow(2,s.length())];
    for(int i = 0; i < pow(2,s.length()); i++) {
        string str = "";
        for(int j = 0; j < s.length(); j++) {
            if((i & 1 << j)) {
                str += s[j];
            }
        }
        result[i] = str;
    }
    for(int i = 0; i < pow(2,s.length()); i++) {
        if(i < pow(2,s.length()) - 1)
            cout << "{" << result[i] << "}, ";
        else 
            cout << "{" << result[i] << "}"; 
    }
    cout << endl;

    return 0;
}