#include <iostream>
using namespace std;

void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int main() {
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
        
    mergeSort(a,0,n-1);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0; 
}

void mergeSort(int *a, int start,int end) {
    if(start < end) {
        int mid = start + (end - start)/2;      // same as (start+end)/2 ... used this to avoid integer overflow
        mergeSort(a,0,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}

void merge(int *a, int start,int mid,int end) {
    int *res = new int[end-start+1];
    int n = mid;
    int m = end;
    int k{0};
    int i{start}, j{mid+1};
    while(i <= n && j <= m) {
        if(a[i] < a[j])
            res[k++] = a[i++];
        else if (a[i] > a[j])
            res[k++] = a[j++];
        else {
            res[k++] = a[i++];
            res[k++] = a[j++];
        }
    }

    while(i <= n)
        res[k++] = a[i++];

    while(j <= m)
        res[k++] = a[j++];
    i = 0;
    for(int l = start; i < k; l++) {
        a[l] = res[i];
        i++;  
    }
}
