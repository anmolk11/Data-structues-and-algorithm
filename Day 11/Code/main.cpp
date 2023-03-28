#include <iostream>
#include <unordered_set>    // <-- hashing
#include <unordered_map>    // <-- hashing
using namespace std;

void set() {
     // unordered_set
    //  1. Does not maintain the order of elements
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(7);

    // for (auto it = s.begin(); it != s.end(); it++) {
        // cout << *it << " ";
    // }

    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    cout << "Size : " << s.size() << endl;
  
    //  clear
    // s.clear();
    // cout << "Size : " << s.size() << endl;
     
    // erase
    // s.erase(1)
    // s.erase(s.begin(),s.end());
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    cout << "Size : " << s.size() << endl;
    
    // find, count
    cout << "Count : " <<  s.count(11) << endl;
    cout << "Find : " << *(s.find(11)) << endl;
}

void map() {
     // unordered_map
    //  1. Does not maintain the order of elements
    unordered_map<string,int> mp;
    mp.insert({"abc",1});
    mp["def"] = 2;

    // for (auto it = mp.begin(); it != mp.end(); it++) {
        // cout << it->first << " : " << it->second << " ";
    // }

    for (auto it : mp) {
        cout << it.first << " : " << it.second << " ";
    }
    cout << endl;
    cout << "Size : " << mp.size() << endl;
  
    //  clear
    // mp.clear();
    // cout << "Size : " << mp.size() << endl;
     
    // erase
    mp.erase("abc");
    // // s.erase(s.begin(),s.end());
    for (auto it : mp) {
        cout << it.first << " ";
    }
    cout << endl;
    cout << "Size : " << mp.size() << endl;
    
    // // find, count
    // cout << "Count : " <<  s.count(11) << endl;
    // cout << "Find : " << *(s.find(11)) << endl;
}

int main () {
   map();
}