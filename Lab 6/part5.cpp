#include <iostream>

class tmpOpInt{
    int i = 1;
    public:
        tmpOpInt(){std::cout<<"+";};
        ~tmpOpInt(){std::cout<<"-";};

        void* operator new(size_t size){
            std::cout<< "tmpOpInt::new: "<< size << " bytes " << std::endl;
            return:: new (size);
        }
        void operator delete(void* p){
            std::cout<<"tmpOpInt::delete"<<std::endl;
            ::delete []p;
        }


};

class tmpOpArray{
    enum{size = 10};
    int iarray[size];
    public:
        tmpOpArray(){std::cout<<"*";};
        ~tmpOpArray(){std::cout<<"~";};

        void* operator new[](size_t size) {
            std::cout << "tmpOpArray::new[]: " << size << " bytes" << std::endl;
            return ::new char[size];
        }
        void operator delete[](void* p) {
            std::cout << "tmpOpArray::delete[]" << std::endl;
            ::delete []p;
        } 
  

};

int main(){
    tmpOpInt* newInt = new tmpOpInt;
    std::cout<<std::endl;
    delete newInt;

    /*
    tmpOpArray* newArray = new tmpOpArray[25];
    std::cout<<std::endl;
    delete []newArray;
    */

    return 0;
}

//A lot of the code is taken from the textbook Thinking in C++ from pages 595 - 605

//just create memory space
//delete memory space
//the difference between question and code in textbook
//is that the code in textbook in the new operator, creates a char array
//we dont want that for the question for single 
//but for array verison, that is okay.