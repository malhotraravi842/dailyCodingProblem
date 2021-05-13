#include<bits/stdc++.h>
using namespace std;

// void print_n(int n) {
//     cout<<n<<endl;
// }

// int sq(int n) {
//     return n*n;
// }

int main() {

    // function<void(int)> num = print_n;
    // function<int(int)> square = sq;

    // num(10);

    // cout<<square(10)<<endl;
    int count=0, c = 0;

    for(int i=1;i<=1000;i++) {
        // if(i%10 == 0 && sqrt(i) - floor(sqrt(i)) != 0) {
        //     count++;
        // }

        if(i%5 != 0 && i%10 != 0 && sqrt(i) - floor(sqrt(i)) == 0) {
            c++;
        }
    }

    cout<<c;

    return 0;
}