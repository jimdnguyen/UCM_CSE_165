#include <iostream>

class arrayInts
{
    static const int size = 5;
    int array[size] = {1, 2, 3, 4, 5};
    const int variable;
    static int j;

public:
    arrayInts() : variable{2} {};
    static int returnJ() { return j; };
    void print();
};

int arrayInts::j = 3;

inline void arrayInts::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
    std::cout << "Static data member: " << returnJ() << std::endl;
}

int main()
{
    arrayInts tmp;
    tmp.print();

    return 0;
}
/*
https://www.geeksforgeeks.org/inline-functions-cpp/
https://stackoverflow.com/questions/21303/in-c-can-constructor-and-destructor-be-inline-functions
https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
https://stackoverflow.com/questions/1900997/expected-expression-before-return
https://stackoverflow.com/questions/5025394/effect-of-return-type-being-static
https://stackoverflow.com/questions/15235526/the-static-keyword-and-its-various-uses-in-c
http://cplusplus.com/forum/beginner/100701/
TA looked over my code/output and said its good
*/