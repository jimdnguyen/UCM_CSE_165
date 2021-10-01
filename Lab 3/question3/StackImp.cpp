#include "StackImp.h"
#include <iostream>
#include <vector>

int chosen = 0;

void StackImp::initialize(int choice){
    chosen = choice;
    if(chosen == 0){
        std::cout<<"Initializing an Array of Ints"<<std::endl;
        head = -1;
    }else if(chosen == 1){
        std::cout<<"Initializing a Vector of Ints"<<std::endl;
    }
}

void StackImp::push(int value){
    if(chosen == 0){
        int tmpHead = head;
        tmpHead = tmpHead + 1;
        array[tmpHead] = value;
        head = tmpHead;
    }else if(chosen == 1){
        vec.push_back(value);
    }
}

void StackImp::pop(){
    if(chosen == 0){
        int popEle = array[head]; 
        int tmpHead = head;
        head = head - 1;
        array[tmpHead] = 0;
    }else if(chosen == 1){
        vec.pop_back();
    } 
}

void StackImp::peek(){
    if(chosen == 0){
        std::cout<<"Current Value in Array: "<<array[head]<<std::endl;

    }else if(chosen == 1){
        std::cout<<"Current Value in Vector: "<<vec.back()<<std::endl;
    }
}

void StackImp::print(){
    if(chosen == 0){
        for(int i = head; i >= 0; i--){
            std::cout<<array[i]<<std::endl;
        }
    }else if(chosen == 1){
        for(int i = vec.size()-1; i >= 0; i--){
            std::cout<<vec.at(i)<<std::endl;
        }
    } 
}

void StackImp::cleanup(){
    if(chosen == 0){
    for(int i = head; i >= 0; i--){
        array[i] = 0;
    }
    }else if(chosen == 1){
        for(int i = vec.size()-1; i >= 0; i--){
            vec.pop_back();
        }
    }
}