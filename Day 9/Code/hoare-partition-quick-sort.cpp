// Hoare's Partition algorithm for quick sort partition function
// make all elements in left of pivot smaller than pivot and right larger than pivot.
// PIVOT should be 1st element of array
// Better in time complexity compared to lomuto partition but does not position piviot to its 
// correct position rather returns the index+1 where all the elements left it are lesser
// and all the elements right to it are greater
#include <iostream>
using namespace std;

int hoarePartition(int*,int,int);

int main() {
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
        
    int j = hoarePartition(a,0,n-1);
    cout << j << endl;

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}

int hoarePartition(int* a, int l, int h) {
    int pivot{a[l]};
    int i{l-1}, j{h+1};
    while(true) {
        do {
            i++;
        } while (a[i] < pivot);
        
        do {
            j--;
        } while (a[j] > pivot);

        if(i >= j)
            return j;
        swap(a[i],a[j]);
    }
}