#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


class Memory{
    int x = 4;
    double y = 2.0;
    float z = 4.0;
    std::string hi = "hi";
    
    public:
    //4 function to return data type
        //int returnX() = {return x;};
        //double y() = {return y);}
        //1 for float
        //1 for string
        
        //virtual void tmp1();
        //virtual void tmp2();

        
};
void calcMemory(Memory& ptr){
    const char* const ptrMemory = reinterpret_cast<char*>(&ptr);
    unsigned char* array = new unsigned char[sizeof(ptr)]; // empty array with size of ptrA
    //std::cout<<ptrMemory<<std::endl;
    //std::cout<<sizeof(ptr)<<std::endl;
    std::copy(ptrMemory, ptrMemory + sizeof(ptr), array);
    for(int i = 0; i < sizeof(ptr); i++){
        std::cout<<array[i]<<std::endl;
    }
    //use pointer as begin to copy elemts in another array
    //use loop to check new array and see if data match and print the length of each data elements
}

int main(){

    Memory tmpMemory;


    calcMemory(tmpMemory);

    return 0;
}

/*

memory != address


*/