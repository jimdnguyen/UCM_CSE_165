#include <iostream>
#include <vector>
#include "PStash.h"

#define size 10

class Counted{
    int id = 0;
    static int count;
    
    public:
        void f(){
            std::cout<<"Hi, Its the F Function for: "<< id <<std::endl;
        }
        Counted() : id(count++){
            std::cout<<"Constructor: "<< id << std::endl;
        }
        ~Counted(){
            std::cout<<"Destructor: " << id << std::endl; 
        }
};

int Counted::count = 0;

int main(){
    /*
    std::vector<Counted*> vecCounted;
       
    for(int i = 0; i < size; i++){
        vecCounted.push_back(new Counted);
    }
    for(int i = 0; i < size; i++){
        vecCounted[i]->f();
    }
    for(int i = 0; i < size; i++){
        delete vecCounted[i];
    }
    */
   PStash tmpStash;
   //Counted hi;

   for(int i = 0; i < size; i++){
       tmpStash.add(new Counted);
   }
   
   for(int j = 0; j < size; j++){
    //Counted tmpCounted = *(Counted*)(tmpStash[j]);
    //tmpCounted.f();
    ((Counted*)tmpStash[j])->f();
      
   }
   ///*
   for(int k = 0; k < size; k++){
       delete (Counted*)tmpStash.remove(k);
   }
   //*/
    return 0;
}

//I reused my code from part3 for part4
//I used code from the textbook Thinking in C++ from pages 586 - 591
