#include <iostream>
#include "StackOfInt.h"

//default case is array of ints
//put 1 in the initialize function to use vectors instead

int main()
{
    StackOfInt stack;
    stack.initialize();// this defaults to use array of ints
    //stack.initialize(1);// this changes to use vector of ints
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(2);
    stack.print();
    stack.pop();
    stack.peek();
    stack.cleanup();

    return 0;
}