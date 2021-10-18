#include <iostream>
#include <string>
#include <vector>

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

    something ptrSomething = something("hi");

int main(){
    int tmpSize = sizeof(ptrSomething);
    ptrSomething = new (tmpSize) something("bye");

    return 0;
}
//can use operator new from question5
//just pass another arguement for string
//can use push back to push back the string
//still need to allocate memory
