// Problem Link: https://www.geeksforgeeks.org/a-product-array-puzzle/

#include<bits/stdc++.h>
using namespace std;

void findProduct(int arr[], int n) {
    int left[n], right[n];
    left[0] = 1;
    right[n-1] = 1;
    for(int i=1;i<n;i++) {
        left[i] = left[i-1]*arr[i-1];
        right[n-i-1] = right[n-i]*arr[n-i];
    }

    for(int i=0;i<n;i++) {
        arr[i] = left[i]*right[i];
    }

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    findProduct(arr, n);

    return 0;
}