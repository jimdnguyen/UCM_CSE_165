#include <iostream>
#include <vector>

#define size 10

class Counted{
    
    int id = 0;
    static int count;

    public:            
        Counted() : id(count++){
            std::cout<<"Constructor: "<< id << std::endl;
        }
        ~Counted(){
            std::cout<<"Destructor: " << id << std::endl; 
        }     
};

int Counted::count = 0;

int main(){
    
    std::vector<Counted*> vecCounted;
       
    for(int i = 0; i < size; i++){
        vecCounted.push_back(new Counted);
    }
    for(int i = 0; i < size; i++){
        delete vecCounted[i];
    }
    return 0;
}

//I reused my code from part1 for part2.
//Websites used for Question 2
//https://www.daniweb.com/programming/software-development/threads/247157/warning-taking-address-of-temporary
//I also used the practice midterm to help me figure it out too
