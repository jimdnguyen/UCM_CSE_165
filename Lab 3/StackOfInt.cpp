#include "StackOfInt.h"
#include "require.h"
#include <iostream>

void StackOfInt::stacksOfInt::initialize(int array, stacksOfInt* nxt){
    value = array;
    next = nxt;
}

void StackOfInt::initialize(){
    head = 0;
}

void StackOfInt::push(int array){
    stacksOfInt* tmp = new stacksOfInt;
    tmp->initialize(array, head);
    head = tmp;
}

void* StackOfInt::pop(){
    if(head == 0){
        return 0;
    }
    int result = head->value;
    stacksOfInt* oldHead = head;
    head = head->next;
    delete oldHead;
    return head;
}

void StackOfInt::peek(){
    require(head != 0, "Stack empty");
    stacksOfInt* tmp = head;
    while(tmp != NULL){
        std::cout << tmp->value << std::endl;
        tmp = tmp->next;
    }
}

void StackOfInt::cleanup(){
    while(pop());
}