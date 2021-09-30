#include <iostream>
#include <vector>
#include <string>

class StringVector : public std::vector<void*>{
   
    std::vector<std::string> sv;
    public:
       void push_back(void* s){
           std::string* tmpS = static_cast<std::string*>(s);
           std::string tmpSt = *tmpS;
           std::cout<<*tmpS<<std::endl;
           sv.push_back(tmpSt);
           std::cout<<sv[0]<<std::endl;
       }  

       void operator[](size_t index){
           std::cout<< sv.at(index)<<std::endl;
       } 
};

int main()
{
    StringVector hi;
    std::string str = "StringVectorpublic";
    void* ptr = &str;
    hi.push_back(ptr);
    hi.operator[](0);

    return 0;
}