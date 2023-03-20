#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // int comparisons{0};
    for(int i = 0; i < n; i++) {
        int pivot = a[i];
        int j = i - 1;
        for( ; j >= 0; j--) {
            if(a[j] > pivot) {
                a[j+1] = a[j];
            }else {
                break;
            }
        }
        a[j+1] = pivot;
    }


    // cout << "Comparisions : " << comparisons << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}