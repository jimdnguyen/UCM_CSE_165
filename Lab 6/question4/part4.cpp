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

   PStash tmpStash;
  

   for(int i = 0; i < size; i++){
       tmpStash.add(new Counted);
   }
   
   for(int j = 0; j < size; j++){

    ((Counted*)tmpStash[j])->f();
      
   }
  
   for(int k = size; k >= 0; k--){
       delete (Counted*)tmpStash.remove(k);
   }
  
    return 0;
}

//I reused my code from part3 for part4
//I used code from the textbook Thinking in C++ from pages 586 - 591
//TA looked over my code/output and says its good
