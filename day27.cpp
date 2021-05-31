#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isBalanced(string s) {
    int n = s.size();
    stack<char> st;
    char c;
    for(int i=0;i<n;i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            c = st.top();
            st.pop();
            if(c == '(' && s[i] != ')') {
                return false;
            }else if(c == '{' && s[i] != '}') {
                return false;
            }else if(c == '[' && s[i] != ']') {
                return false;
            }
        }
    }

    if(st.empty()) {
        return true;
    }else{
        return false;
    }
}

int main() {
    int t;
    cin>>t;
    while(t) {
        string s;
        cin>>s;

        if(isBalanced(s)) {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        t--;
    }

    return 0;
}