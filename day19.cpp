#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minCostUtil(vector<int> arr, int k, int &prevIndex) {
    int minm = INT_MAX;
    int index = prevIndex;
    for(int i=0;i<k;i++) {
        if(arr[i] < minm && i != prevIndex) {
            minm = arr[i];
            index = i;
        }
    }

    prevIndex = index;
    return minm;
}

int minCost(vector<vector<int>> arr, int n, int k) {
    int prev = -1;
    int cost = 0;

    for(int i=0;i<n;i++) {
        cost += minCostUtil(arr[i], k, prev);
    }

    return cost;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<vector<int>> arr(n, vector<int> (k));
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            cin>>arr[i][j];
        }
    }

    cout<<minCost(arr, n, k);

    return 0;
}

//Input:  [[1,2,3,4], [1,2,1,0], [6,1,1,5], [2,3,5,5]]
// Output: 4