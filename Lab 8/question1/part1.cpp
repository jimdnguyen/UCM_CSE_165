#include <iostream>
#include <cstring>

#define size 5

class arrayChar
{
    char array[size];

public:
    arrayChar() { std::memset(array, ' ', sizeof(array)); }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i];
        }
    }
};

int main()
{
    arrayChar tmp;
    tmp.print();
    return 0;
}
//https://en.cppreference.com/w/cpp/string/byte/memset
//TA looked over the code and said its good