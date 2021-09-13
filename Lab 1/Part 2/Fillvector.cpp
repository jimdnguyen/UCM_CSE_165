//: C02:Fillvector.cpp
// Copy an entire file into a vector of string
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


int main() {
    std::string concatenates;
    std::ifstream in("Fillvector.cpp");
    std::string line;

    while(getline(in, line))
    {
        concatenates += line;
        concatenates += "\n";
    }
 
    concatenates.erase(std::remove(concatenates.begin(),concatenates.end(), '\n'), concatenates.end());
    concatenates.erase(std::remove(concatenates.begin(),concatenates.end(), '\r'), concatenates.end());

    std::cout<<concatenates<<std::endl;
   
    
} ///:~ 

// The majority of this code was grabbed from the textbook Thinking in C++ 2nd edition Volume 1
// I used this website https://stackoverflow.com/questions/1488775/c-remove-new-line-from-multiline-string to help me understand how to remove newlines from string to make it one long single string
