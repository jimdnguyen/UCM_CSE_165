//: C03:printBinary.cpp {O}
#include <iostream>
void printBinary(const unsigned char val) {

    for(int i = 7; i >= 0; i--)
    {

        if(val & (1 << i))
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
     
    }
} ///:~

//this code is given in textbook on page 173
