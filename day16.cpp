#include<iostream>
using namespace std;

class Log {
    private: 
        int maxSize;
        int *buffer;
        int currIndex;

    public:
        Log(int maxSize);
        void record(int orderId);
        int get_last(int index);
};

Log::Log(int size) {
    maxSize = size;
    buffer = new int[maxSize];
    currIndex = 0;
}

void Log::record(int orderId) {
    buffer[currIndex] = orderId;
    currIndex++;
}

int Log::get_last(int index) {
    return buffer[(currIndex-index + maxSize)%maxSize];
}

int main() {
    Log order(10);
    order.record(1);
    order.record(2);
    order.record(3);
    order.record(4);
    order.record(5);
    order.record(6);
    order.record(7);
    order.record(8);
    order.record(9);
    order.record(10);

    cout<<(order.get_last(2))<<endl;
    cout<<(order.get_last(3))<<endl;

    return 0;
}