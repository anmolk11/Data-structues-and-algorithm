#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool anagram(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2)
    {
        return false;
    }
    int count[256] = {0};
    for (int i = 0; i < n1; i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    cout << "Are both string anagram of each other ? " << (anagram(str1, str2) ? "Yes" : "No") << endl;
    reverse(str1.begin(), str1.end());
    cout << "Reverse string str1 : " << str1 << endl;
}