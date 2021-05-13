// Problem Link: https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/

#include<bits/stdc++.h>
using namespace std;

string pairExist(int arr[], int n, int k) {
    sort(arr, arr+n);
    int i=0, j=n-1;

    while(i<j) {
        int temp = arr[i] + arr[j];
        if(temp == k) {
            return "YES";
        }else if(temp > k) {
            j--;
        }else {
            i++;
        }
    }

    return "NO";
}

bool isExist(int arr[], int n, int k) {
    unordered_map<int, int> m;
    for(int i=0;i<n;i++) {
        m[arr[i]]++;
    }

    for(int i=0;i<n;i++) {
        int diff = k - arr[i];
        
        if(diff == arr[i] & m[diff]>1) return true;

        if(m.find(diff) != m.end()){
            return true;
        }else {
            return false;
        }
    }
}



int main() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<pairExist(arr, n, k)<<endl;

    return 0;
}
