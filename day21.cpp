#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    if(v1[0] == v2[0]) {
        return v1[1]<v2[1];
    }

    return v1[0] < v2[0];
}

void printArray(vector<vector<int>> v, int n) {
    for(int i=0;i<n;i++) {
        cout<<"["<<v[i][0]<<","<<v[i][1]<<"], ";
    }
    cout<<endl;
}

int roomRequired(vector<vector<int>> v, int n) {
    sort(v.begin(), v.end(), compare);

    printArray(v, n);

    queue<int> q;
    int count=1;
    q.push(v[0][1]);
    for(int i =1;i<n;i++) {
        int f = q.front();
        if(f >= v[i][0]){
            count++;
        }else {
            q.pop();
        }

        q.push(v[i][1]);
    }
    
    return count;
}

int main () {
    int n;
    cin>>n;

    vector<vector<int>> v(n, vector<int>(2));
    for(int i=0;i<n;i++) {
        cin>>v[i][0]>>v[i][1];
    }

    cout<<"Room Required: "<<roomRequired(v, n)<<endl;

    return 0;
}

// Input:
//     0 50
//     30 75
//     60 150
//     10 87
//     100 120
//     40 80
//     150 200

// Output : 4