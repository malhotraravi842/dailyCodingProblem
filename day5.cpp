// Problem Link:  https://numbergeneral.github.io/dailycodingproblem05/#

#include<bits/stdc++.h>
using namespace std;

function<int (int(*f)(int, int ))> cons(int a, int b) {
    auto pair = [a, b] (int(*f)(int, int)) -> int {
        return (*f)(a, b);
    };

    return pair;
}

int car(function<int (int(*f)(int, int))> cons) {
    auto get_a = [](int a, int b) -> int{
        return a;
    };

    return cons(*get_a);
}

int cdr(function<int (int(*f)(int, int))> cons) {
    auto get_b = [](int a, int b) -> int {
        return b;
    };

    return cons(*get_b);
}

int main() {
    function<int (int(*f)(int, int))> cons_v = cons(5, 2);
    int a = car(cons_v);
    int b = cdr(cons_v);
    
    cout << "The value of a is: " << a << "\n";
    cout << "The value of b is: " << b << "\n";

    return 0;
}