// Problem Link : https://www.geeksforgeeks.org/wildcard-pattern-matching/

#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

// Bruteforce(Not valid)

// bool isValid(string re, string s) {
//     int size = s.size();
//     int reSize = re.size();
//     int i=0, j=0;
//     bool flag = true;
//     while(i<size && j<reSize) {
//         if(re[j] == '.'){
//             if(j == size-1){
//                 return true;
//             }else {
//                 j++;
//             }
//         }else if(re[j] == '*'){
//             if(i <= size-2) {
//                 return true;
//             }else {
//                 j++;
//             }
//         }else if(re[i] != s[i]) {
//             return false;
//         }else {
//             i++;
//             j++;
//         }
//     }
//     return false;
// }



bool strmatch(string str, string pattern)
{   
    int n = str.size();
    int m = pattern.size();
    if (m == 0)
        return (n == 0);

    bool lookup[n + 1][m + 1];
 
    memset(lookup, false, sizeof(lookup));
 
    lookup[0][0] = true;
 
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '*')
                lookup[i][j]
                    = lookup[i][j - 1] || lookup[i - 1][j];
 
            else if (pattern[j - 1] == '.'
                     || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];
 
            else
                lookup[i][j] = false;
        }
    }
 
    return lookup[n][m];
}

int main() {
    int t;
    cin>>t;
    while(t) {
        string re, s;
        cin>>re>>s;
        if(strmatch(s, re)) {
            cout<<"Yes"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
        t--;
    }

    return 0;
}