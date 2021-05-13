// Problem Link: https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

#include<bits/stdc++.h>
using namespace std;

int segregate(int *arr, int n) {
    int i, j=0;

    for(int i=0;i<n;i++) {
        if(arr[i]<=0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return j;
}

int findMissingUtil(int arr[], int n) {

    int i;

    for(i=0;i<n;i++){
        if(abs(arr[i])-1 < n && arr[abs(arr[i])-1] > 0) {
            arr[abs(arr[i])-1] *= -1;
        }
    }

    for(i=0;i<n;i++){
        if(arr[i]>0){
            return i+1;
        }
    }

    return n+1;
}

int findMissing(int arr[], int n) {
    int shift = segregate(arr, n);

    return findMissingUtil(arr+shift, n-shift);
}

int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<findMissing(arr, n)<<endl;

    return 0;
}