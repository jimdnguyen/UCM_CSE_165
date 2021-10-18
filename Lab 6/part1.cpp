#include <iostream>

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
    
    Counted();
    return 0;
}

//websites that helped me with queston1
//http://cplusplus.com/forum/beginner/100701/
//https://stackoverflow.com/questions/55329892/what-does-this-compiler-error-means-qualified-id-in-declaration-before-to