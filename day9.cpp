#include<iostream>
using namespace std;

int largestSum(int arr[], int n) {
    int sum = arr[0], prev=0, prev2=0;
    for(int i=1;i<n;i++) {
        if(i - prev>=2) {
            sum += arr[i];
            prev2 = prev;
            prev = i; 
        }else {
            if(arr[i] > arr[prev]) {
                sum = sum - arr[prev] + arr[i];
                prev2 = prev;
                prev = i;
            }
        }

        if(prev - prev2 >=2) {
            sum += arr[prev2];
        }
    }

    return sum;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<largestSum(arr, n)<<endl;

    return 0;
}