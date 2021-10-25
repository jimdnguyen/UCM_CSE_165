#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <new>
#include <iostream>

/*

class something{
    int i = 0;
    static std::vector<std::string> vecString;
    public:
        something(std::string tmp){
            std::cout<<"something constructor called" <<std::endl;
            vecString.push_back(tmp);
        }

        ~something(){
            std::cout<<"something destructor called"<<std::endl;
        }
        int size(){
            return vecString.size();
        }
        std::string senLoc(int i){
            return vecString.at(i);
        }
};

    //something ptrSomething = something("hi");
*/


struct macro{
    macro(int line, const std::string& file): line(line), file(file){}
    std::string file;
    int line;

};

#define macroCons() macro(__LINE__, __FILE__);

class readVecString{
    static std::vector<std::string> holdString;
    public:
        readVecString(std::string tmpString){
            holdString.push_back(tmpString);
            printf("readVecString Constructor\n");
        }
        ~readVecString(){printf("readVecString Destructor\n");};
        /*
        void* operator new(size_t size){
            printf("operator new: %lu Bytes\n", size);
            void* m = malloc(size);
            if(!m){
                puts("out of memory");
            }
            return m;
        }
        void operator delete(void* m){
            puts("operator delete\n");
            free(m);
        }
        */
       void pushBack(std::string tmpString){
           holdString.push_back(tmpString);
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
    void* p = memory;
    std::string tmp = "hi";

    readVecString* tmpVecString = new (p) readVecString(tmp);
    //tmpVecString->pushBack(tmp);

    tmpVecString->print();

    tmpVecString->readVecString::~readVecString();
    //::operator delete(tmpVecString);

    macro m1 = macroCons();
    std::cout<<m1.line<<"\n";

    return 0;
}
//can use operator new from question5
//just pass another arguement for string
//can use push back to push back the string
//still need to allocate memory

/*
 void* operator new(size_t size){
            printf("operator new: %d Bytes\n", size);
            void* m = malloc(size);
            if(!m){
                puts("out of memory");
            }
            return m;
        }
        void operator delete(void* m){
            puts("operator delete\n");
            free(m);
        }
*/

/*
list of websites that I looked at for this lab
https://stackoverflow.com/questions/46263018/correct-way-of-implementing-placement-new-in-c
https://stackoverflow.com/questions/10865957/printf-with-stdstring



*/