#include<iostream>
#include<vector>
using namespace std;

// Unoptimized solution
int maxValue(vector<int> arr, int start, int end) {
    int n = arr.size();
    int maxm = arr[start];
    for(int i=start+1;i<end;i++) {
        maxm = max(arr[i], maxm);
    }

    return maxm;
}

vector<int> maxValueOfLenK(vector<int> arr, int n, int k) {
    if(k==1) {
        return arr;
    }
    vector<int> ans;
    int maxm;
    for(int i=0;i<n-k+1;i++) {
        maxm = maxValue(arr, i, i+k);
        ans.push_back(maxm);
    }

    return ans;
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    vector<int> ans = maxValueOfLenK(arr, n, k);

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }

    return 0;
}