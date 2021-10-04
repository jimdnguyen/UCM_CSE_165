#include <iostream>

#define n 5

class arrayInt{
    int array[n] = {5,2,3,6,9};
    
    public:
        
        int* ptr = array;
        int (*arrPtr) [n] = &array;
};

int main(){

    arrayInt tmp;
    
    for(int i = 0; i < n; i++){
        std::cout<<*(*(tmp.arrPtr) + i)<<std::endl;
        //std::cout<<*(tmp.ptr + i)<<std::endl; This was my first thought before I looked at stackflow
    }
    
    return 0;
}
//TA recommended me to look up array pointer
//I found this stackflow question about it and used it to solve my issue 
//https://stackoverflow.com/questions/60371230/c-print-address-of-pointer-to-array-problem