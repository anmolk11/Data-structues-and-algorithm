#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int comparisons{0};

    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1;j < n; j++) {
            if(comparisons++ & a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i],a[min]);
    }


    cout << "Comparisions : " << comparisons << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}

// 5
// [3,7,1,2,0]

// ITR : 1 , MIN : 3
// [3,7,1,2,0]
    // MIN : 1
    // MIN : 0
