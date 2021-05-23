#include<iostream>
#include<time.h>
using namespace std;

int selectRandom(int x) {
    static int res;
    static int count=0;

    count++;

    if(count==1) {
        res = x;
    }else {
        int i = rand()%count;
        if(i==count-1) {
            res = x;
        }
    }

    return res;
}

int main() {
    int stream[] = {1, 2, 3, 4}; 
    int n = sizeof(stream) / sizeof(stream[0]); 
  
    // Use a different seed value for every run. 
    srand(time(NULL)); 
    for (int i = 0; i < n; ++i) 
        cout << "Random number from first " << i + 1 
             << " numbers is " << selectRandom(stream[i]) << endl; 
    return 0; 
}

