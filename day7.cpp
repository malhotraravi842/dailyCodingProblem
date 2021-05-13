// Problem Link: https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

// string getNextVal(string s, int index, int l) {
//     int size = s.size();
//     if(index >= size) return "";

//     string str = "";
//     while(l && index<size) {
//         str += s[index];
//         index++;
//         l--;
//     }

//     return str;
// }

// void decode(string s, string str, string val, int index) {
//     int size = s.size();

//     if(val != "") {
//         int num = stoi(val);
//         if(num>0 && num<=26) {
//             str += (char)(96+num);
//         }else {
//             return;
//         }
//     }

//     if(index== size) {
//         cout<<str<<endl;
//         return;
//     }else if(index>size) {
//         return;
//     }

//     decode(s, str, getNextVal(s, index, 1), index+1);
//     decode(s, str, getNextVal(s, index, 2), index+2);
// }

int countDecoding(string digits, int n) {
    if(n==0 || n==1) return 1;

    if(digits[0] == '0') return 0;

    int count=0;
    if(digits[n-1]>'0'){
        count = countDecoding(digits, n-1);
    }

    if(digits[n-2] == '1' || (digits[n-2]=='2' && digits[n-1] < '7')) {
        count += countDecoding(digits, n-2);
    }

    return count;
}

int countWays(string digits, int n) {
    if(n==0 || (n==1 && digits[0]=='0')) {
        return 0;
    }

    return countDecoding(digits, n);
}


int main() {
    string digits;
    cin>>digits;

    cout<<countWays(digits, digits.size());

    return 0;
}