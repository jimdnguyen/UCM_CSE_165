#include <iostream>
#include <vector>

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
    
    std::vector<Counted*> vecCounted;
       
    for(int i = 0; i < size; i++){
        vecCounted.push_back(new Counted);
    }
    for(int i = 0; i < size; i++){
        vecCounted[i]->f();
    }
    for(int i = size; i >= 0; i--){
        delete vecCounted[i];
    }
    return 0;
}

//I reused my code from part2 to part3
//TA looked over my code/output and says its good