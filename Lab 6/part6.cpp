#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <new>
#include <iostream>

class readVecString{
    static std::vector<std::string> holdString;
    public:
        readVecString(std::string tmpString){
            holdString.push_back(tmpString);
            printf("readVecString Constructor\n");
        }
        ~readVecString(){printf("readVecString Destructor\n");};
        
        void* operator new(size_t size, std::string tmpString){
            void* m = malloc(size);
            if(!m){
                puts("out of memory");
            }
            return m;
        }
       void print(){
           for(int i = 0; i < holdString.size();i++){
               std::cout<< holdString.at(i)<<std::endl;
           }
       }

};

std::vector<std::string> readVecString::holdString;


int main(){
    char memory[sizeof(readVecString)];
    std::string tmp = "hi";
    std::string tmp2 = "bye";

    readVecString* tmpVecString = new (memory) readVecString(tmp);

    tmpVecString->print();

    tmpVecString = new (memory) readVecString(tmp2);

    tmpVecString->print();

    tmpVecString->readVecString::~readVecString();
    

    return 0;
}
//can use operator new from question5
//just pass another arguement for string
//can use push back to push back the string
//still need to allocate memory
//most of my code mainly came from the code that is given to us from the lecture slides lecture 13(2) from the professor 
//and the textbook Thinking in C++ on pages 607-609


/*
 void* operator new(size_t size){
            printf("operator new: %d Bytes\n", size);
            void* m = malloc(size);
            if(!m){
                puts("out of memory");
            }
            return m;
        }
*/

/*
list of websites that I looked at for this lab
https://stackoverflow.com/questions/46263018/correct-way-of-implementing-placement-new-in-c
https://stackoverflow.com/questions/10865957/printf-with-stdstring
*/