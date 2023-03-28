// Count distinct elements in an array
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int naive(vector<int> a, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                found = true;
            }
        }
        if (!found) {
            ans++;
        }
    }
    return ans;
}

int hashing(vector<int> a, int n) {
    unordered_set<int> s;
    // for (int i = 0; i < n; i++) {
        // s.insert(a[i]);
    // }
    for (auto it : a ) {
        s.insert(it);
    }
    return s.size();
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

        // int ans = naive(a, n);
        int ans = hashing(a, n);
        cout << ans << endl;
    }
    return 0;
}

// [15 