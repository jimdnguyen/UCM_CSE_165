#include "StackOfInt.h"
#include <vector>

struct StackOfInt::stacksOfInt{
    int i;
    std::vector<int> i2;
};

void StackOfInt::initialize(){
    ptr = new stacksOfInt;
    ptr->i = 0;
}

void StackOfInt::cleanup(){
    delete ptr;
}