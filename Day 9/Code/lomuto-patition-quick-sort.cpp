// lomuto Partition algorithm for quick sort partition function
// make all elements in left of pivot smaller than pivot and right larger than pivot.
#include <iostream>
using namespace std;

void partition(int*,int,int);

int main() {
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
        
    int p;
    cin >> p;
    partition(a,n,p);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}

void partition(int* a, int n, int p) {
    int i{-1};
    swap(a[p],a[n-1]);
    p = n-1;
    for(int j = 0; j < n-1; j++) {
        if(a[j] < a[p]) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[n-1]);
}