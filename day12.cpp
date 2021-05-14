// Problem Link: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/

#include<iostream>
using namespace std;


void countSteps(int n, int i, int &count) {
    if(i==n) count++;

    if(i>n) return;

    countSteps(n, i+1, count);
    countSteps(n, i+2, count);
}

int main() {
    int n;
    cin>>n;

    int count = 0;

    countSteps(n, 0, count);

    cout<<count<<endl;
}