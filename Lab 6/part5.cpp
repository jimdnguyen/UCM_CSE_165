#include <cstdio>
#include <cstdlib>

class tmpOpInt{
    int i[100];
    public:
        tmpOpInt(){//puts("tmpOpInt::tmpOpInt()");
            puts("tmpOpInt Default Constructor");
        };
        ~tmpOpInt(){//puts("tmpOpInts::~tmpOpInt()");
            puts("tmpOpInt Destructor");
        };

        void* operator new(size_t size){
            //printf("==>new: %lu bytes\n", size);
            //return ::new char[size];
            printf("operator new: %lu Bytes\n", size);
            void*p = malloc(size);
            return p;
            
        }
        void operator delete(void* p){
            printf("==>delete\n");
            free(p);
        }

        void* operator new[](size_t size){
            //printf("==>new[]: %lu bytes\n", size);
            //return ::new char[size];
            printf("operator new: %lu Bytes\n", size);
            void*p = malloc(size);
            return p;
            
        }
        void operator delete[](void* p){
            printf("==>delete[]\n");
            free(p);
        }
};

int main(){
    puts("creating & destroying tmpOpInt");
    tmpOpInt* newInt = new tmpOpInt;
    delete newInt;

    puts("creating & destroying tmpOpArray");
    tmpOpInt* newArray = new tmpOpInt[3];
    delete []newArray;

    return 0;
}

//A lot of the code is taken from the textbook Thinking in C++ from pages 595 - 605

//just create memory space
//delete memory space
//the difference between question and code in textbook
//is that the code in textbook in the new operator, creates a char array
//we dont want that for the question for single 
//but for array verison, that is okay.

//most of my code main fro the code given in from lecture 13(2) from the professor
//looks like for me, my operator new holds an extra 8 bytes to store info
