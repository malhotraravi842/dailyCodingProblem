#include<iostream>
#include<functional>
#include<windows.h>
using namespace std;

void print_fun(int n) {
    cout<<n;
}

void callFunc(function<void(int)> func, int n) {
    Sleep(n);
    func(15);
}

int main() {
    int n;
    cin>>n;
    callFunc(print_fun, n);

    return 0;
}