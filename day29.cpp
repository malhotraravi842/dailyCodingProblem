#include<iostream>
#include<string>
#include <sstream>
using namespace std;

string encode(string s) {
    int n = s.size();
    string encode = "";
    int prevIndex = 0;
    int count = 1;

    for(int i=1;i<n;i++) {
        if(s[prevIndex] != s[i]) {
            encode += to_string(count) + s[prevIndex];
            count=1;
        }else {
            count++;
        }

        prevIndex = i;

        if(i==n-1) {
            encode += to_string(count) + s[i];
        }
    }

    return encode;
}

int extractInt(string s, int &index) {
    int n = s.size();
    string num = "";
    while(index<n) {
        int k = (int)s[index];
        if(k >= 48 && k<=57) {
            num += s[index];
            index++;
        }else {
            break;
        }
    }

    stringstream str(num);
    int x = 0;
    str >> x;
    return x;
}

string decode(string s) {
    int n = s.size();
    string decode="";
    int count;
    int i=0;

    while(i<n) {
        int num = extractInt(s, i);
        while(num) {
            decode += s[i];
            num--;
        }
        i++;
    }

    return decode;
}

int main(){
    string s;
    cin>>s;

    s = encode(s);
    cout<<"Encoding : "<<s<<endl;

    s = decode(s);

    cout<<"Decoding : "<<s<<endl;

    return 0;
}