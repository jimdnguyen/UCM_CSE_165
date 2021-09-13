#include <iostream>
#include <declaration.h>

int sum(int x,int y)
{
    std::cout << "Function name is sum" << std::endl;
    std::cout << "Arguement List is int x, int y" << std::endl;
    std::cout << "Return Type is int" << std::endl;
    int z = 0;
    z = x + y;
    return z;
}
char word(char a, char b)
{
    std::cout << "Function name is word" << std::endl;
    std::cout << "Arguement List is char a, char b" << std::endl;
    std::cout << "Return Type is char" << std::endl;
    char c;
    c = a + b;
    return c;
}
float decimal(float z,float v)
{
    std::cout << "Function name is decmial" << std::endl;
    std::cout << "Arguement List is float z, float v" << std::endl;
    std::cout << "Return Type is float" << std::endl;
    float c = 0.0;
    c = z + v;
    return c;
}
void isVoid(int q,int w)
{
    std::cout << "Function name is isVoid" << std::endl;
    std::cout << "Arguement List is int q, int w" << std::endl;
    std::cout << "Return Type is void" << std::endl;
    q = w = 0; 
}