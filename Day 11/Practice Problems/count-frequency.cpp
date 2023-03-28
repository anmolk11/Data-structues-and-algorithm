// Count frequency of elements in an array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void naive(vector<int> a, int n) {
    // Count frequency of each element in the array using naive approach
    for (int i = 0; i < n; i++) {
        // check if this element is already counted
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                found = true;
            }
        }
        if (found)  continue;
        
        // count frequency of a[i]
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        cout << a[i] << " " << count << endl;
    }
}

void hashing(vector<int> a, int n) {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // naive(a, n);
        hashing(a, n);
        cout << "----" << endl;
    }
    return 0;
}