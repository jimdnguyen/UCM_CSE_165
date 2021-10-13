#include <iostream>
#include <algorithm>
#include <cstring>


class Memory{
    int x = 4;
    double y = 22.5;
    float z = 10.4;
    char a = 'a';
    
    public:
    //4 function to return data type
        int returnX(){
            return x;
        };
        double returnY(){
            return y;
        };
        float returnZ(){
            return z;
        };
        char returnA(){
            return a;
        };
        
        virtual void tmp1(){std::cout<<"Virtual 1"<<std::endl;};
        virtual void tmp2(){std::cout<<"Virtual 1"<<std::endl;};

        
};
void calcMemory(Memory& ptr){
    const char* const ptrMemory = reinterpret_cast<char*>(&ptr);
    unsigned char* array = new unsigned char[sizeof(ptr)]; // empty array with size of ptrA
    std::cout<<"Size of Memory Class:" <<sizeof(ptr)<<std::endl;
    std::copy(ptrMemory, ptrMemory + sizeof(ptr), array);
    int tmpInt; double tmpDouble; float tmpFloat; char tmpChar;
    int offsetInt = 0, offsetDouble = 0, offsetFloat = 0, offsetChar = 0;
    
    for(int i = 0; i < sizeof(ptr); i++){
        std::memcpy(&tmpInt, (array + i), sizeof(tmpInt));
        std::memcpy(&tmpDouble, (array + i), sizeof(tmpDouble));
        std::memcpy(&tmpFloat, (array + i), sizeof(tmpFloat));
        std::memcpy(&tmpChar, (array + i), sizeof(tmpChar));
        if(tmpInt == ptr.returnX()){
            offsetInt = i;
            std::cout<<"Integer:"<<ptr.returnX()<<" found!"<<std::endl;
            std::cout<<"Starting Location is:"<<offsetInt<<std::endl;
        }
        if(tmpDouble == ptr.returnY()){
            offsetDouble = i;
            std::cout<<"Double:"<<ptr.returnY()<<" found!"<<std::endl;
            std::cout<<"Starting Location is:"<<offsetDouble<<std::endl;
        }
        if(tmpFloat == ptr.returnZ()){
            offsetFloat = i;
            std::cout<<"Float:"<<ptr.returnZ()<<" found!"<<std::endl;
            std::cout<<"Starting Location is:"<<offsetFloat<<std::endl;
        }
        if(tmpChar == ptr.returnA()){
            offsetChar = i;
            std::cout<<"Char:"<<ptr.returnA()<<" found!"<<std::endl;
            std::cout<<"Starting Location is:"<<offsetChar<<std::endl;
        }
       
    }
    std::cout<<"The length of the Integer Element:" << ptr.returnX() << " is " << offsetDouble - offsetInt << std::endl;
    std::cout<<"The length of the Double Element:" << ptr.returnY() << " is " << offsetFloat - offsetDouble << std::endl;
    std::cout<<"The length of the Float Element:" << ptr.returnZ() << " is " << offsetChar - offsetFloat << std::endl;
    std::cout<<"The length of the Char Element:" << ptr.returnA() << " is " << sizeof(ptr) - offsetChar << std::endl;
    //use pointer as begin to copy elemts in another array
    //use loop to check new array and see if data match and print the length of each data elements
}

int main(){

    Memory tmpMemory;


    calcMemory(tmpMemory); // to change values, need to go to lines 7,8,9,10.

    return 0;
}

/*

memory != address


*/
// used these 2 websites and TA to help me finish this code
//https://stackoverflow.com/questions/49823000/c-fail-to-convert-unsigned-char-array-to-double
//https://www.programiz.com/cpp-programming/library-function/cstring/memcpy