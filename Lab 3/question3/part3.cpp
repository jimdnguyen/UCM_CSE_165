#include <iostream>
#include "StackOfInt.h"

//default case is array of ints
//put 1 in the initialize function to use vectors instead

//atm the maximum length of the fixed array is 5
//to change the length, you need to go to StackImp.h that is in the same folder as this file and change the #define n to be whatever number you want.

int main()
{
    StackOfInt stack;
    stack.initialize();// this defaults to use array of ints or use 0 inside the parenthesis
    //stack.initialize(0); this also defaults to use array of ints
    //stack.initialize(1);// this changes to use vector of ints
    
    //to change the output, do some random combinations of push, peek, print, pop, just do cleanup last.
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