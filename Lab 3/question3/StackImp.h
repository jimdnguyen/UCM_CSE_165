#ifndef StackImp_h
#define StackImp_h
#include <vector>

#define n 5 // change this to increase the size of the fixed array

class StackImp{
    int head;
    int array[n];
    std::vector<int> vec;
    public:
        void initialize(int choice = 0);
        void push(int value);
        void peek();
        void pop();
        void print();
        void cleanup();
};

#endif