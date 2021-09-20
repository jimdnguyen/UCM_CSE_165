#include <iostream>
#include <string>

typedef struct TwoStrOneInt
{
    std::string str1 = "Initialized 1";
    std::string str2 = "Initialized 2";
    int int1 = 1;

} TwoStrOneInt;

int main()
{

    TwoStrOneInt tsoi1;
    TwoStrOneInt* ptr = &tsoi1;

    std::cout<<tsoi1.str1<<std::endl;
    std::cout<<tsoi1.str2<<std::endl;
    std::cout<<tsoi1.int1<<std::endl;

    ptr->str1 = "Changed 1";
    ptr->str2 = "Changed 2";
    ptr->int1 = 2;

    std::cout<<ptr->str1<<std::endl;
    std::cout<<ptr->str2<<std::endl;
    std::cout<<ptr->int1<<std::endl;


    return 0;
}

//I mainly used the textbook Thinking C++ page 192 to help me with this lab