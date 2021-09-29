#include "StackOfInt.h"

void StackOfInt::initialize(int choice){
   stackData.initialize(choice);
}

void StackOfInt::push(int value){
   stackData.push(value);
}

void StackOfInt::pop(){
   stackData.pop();
}

void StackOfInt::peek(){
    stackData.peek();
}

void StackOfInt::print(){
   stackData.print();
}

void StackOfInt::cleanup(){
   stackData.cleanup();
}

