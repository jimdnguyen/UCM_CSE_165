#ifndef StackOfInt_h
#define StackOfInt_h

#include "StackImp.h"


class StackOfInt
{
    StackImp stackData;
    public:
        void initialize(int choice = 0);
        void push(int value);
        void peek();
        void pop();
        void print();
        void cleanup();
};

#endif