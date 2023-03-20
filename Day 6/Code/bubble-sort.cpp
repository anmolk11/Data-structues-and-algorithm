#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a,a+n,greater<int>());

    // int comparisons{0};
    // bool checkFlag{true};
    // for(int i = 0; i < n-1 && checkFlag; i++) {
    //     checkFlag = false;
    //     for(int j = 0; j < n-i-1; j++) {
    //         if(comparisons++ && a[j] > a[j+1]) {
    //             swap(a[j],a[j+1]);
    //             checkFlag = true;
    //         }
    //     }
    // }
    
    // cout << "Comparisions : " << comparisons << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}

// 0 --- n-1

// ITR : 1 : N
// [3,7,1,2,0]
// [3,1,7,2,0]
// [3,1,2,7,0]
// [3,1,2,0,7]

// ITR : 2 : N - 1 ~ N
// [3,1,2,0,7]
// [1,3,2,0,7]
// [1,2,3,0,7]
// [1,2,0,3,7]

// ...

// N * N = N^2
// Time Complexity : O

// [0,1,2,3,7]

// asc :
    // - condition : a[i] > a[j] where (i < j)
        // - true : Swap
        // - false : continue
// [0,1,2,3,7]