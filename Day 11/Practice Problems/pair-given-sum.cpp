// Find if there is a pair with given sum in the array
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void naive(vector<int> a, int n, int sum) {
    // Find if there is a pair with given sum in the array using naive approach
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == sum) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

void hashing(vector<int> a, int n, int sum) {
    unordered_set<int> s(a.begin(),a.end());
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s.find(sum - a[i]) != s.end()) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, sum;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> sum;

        naive(a, n, sum);
        // hashing(a, n, sum);
 
    }
    return 0;
}