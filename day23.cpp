// Prorblem Link: https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

#include<iostream>
#include<vector>
#include<utility>
#include<limits.h>
using namespace std;

bool isSafe(vector<vector<int>> matrix, int row, int col, vector<vector<bool>> visited){
    int r = matrix.size();
    int c = matrix[0].size();
    return (row>=0 && row<r && col>=0 && col<c && matrix[row][col] && !visited[row][col]);
}

void DFS(vector<vector<int>> matrix, pair<int, int> s, pair<int, int> e, vector<vector<bool>> visited, int count, int &minCount){

    if(s.first == e.first && s.second == e.second) {
        minCount = min(count, minCount);
    }

    static int row[] = {-1, 0, 0, 1};
    static int col[] = {0, -1, 1, 0};

    visited[s.first][s.second] = true;
    
    for(int i=0;i<4;i++) {
        if(isSafe(matrix, s.first + row[i], s.second + col[i], visited)){
            s.first += row[i];
            s.second += col[i];
            DFS(matrix, s, e, visited, count+1, minCount);
            s.first -= row[i];
            s.second -= col[i];
        }
    }
}

int shortestPath(vector<vector<int>> matrix, pair<int, int> s, pair<int, int> e){
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<bool>> visited(r, vector<bool> (c, false));
    int minCount = INT_MAX;

    if(matrix[s.first][s.second]) {
        visited[s.first][s.second] = true;
        DFS(matrix, s, e, visited, 0, minCount);
    }else {
        return -1;
    }

    return minCount;
}

int main() {
    int m, n;

    m = 4, n = 4;

    // cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int> (n));
    matrix =  {{1, 1, 1, 1},{0, 0, 1, 0},{1, 1, 1, 1},{1, 1, 1, 1}};

    pair<int, int> s(3, 0);
    pair<int, int> e(0, 0);

    // cin>>s.first>>s.second>>e.first>>e.second;
    // for(int i=0;i<m;i++) {
    //     for(int j=0;j<n;j++) {
    //         cin>>matrix[i][j];
    //     }
    // }

    cout<<shortestPath(matrix, s, e)<<endl;

    return 0;
}