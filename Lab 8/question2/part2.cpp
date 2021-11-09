#include <iostream>
#include <string>

class Bird
{

public:
    std::string bmem = "Bird #";
    static int tmp;
    Bird()
    {
        tmp = tmp + 1;
        //std::cout << bmem << tmp << std::endl;
        bmem = bmem + std::to_string(tmp);
    }
    //look at 566 for << ostream
    Bird &operator=(const Bird &next)
    {
        std::cout << "using overloaded =" << std::endl;
        // std::cout << this->bmem << std::endl;
        // std::cout << next.bmem << std::endl;
        if (this == &next)
        {
            return *this;
            //std::cout << this->bmem << std::endl;
        }
        bmem = next.bmem;
        return *this;
        //std::cout << this->bmem << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &os, const Bird &next);
};

std::ostream &operator<<(std::ostream &os, const Bird &next)
{
    std::cout << "using overloaded <<" << std::endl;
    os << next.bmem;
    return os;
}

int Bird::tmp;

int main()
{
    Bird tmp1;
    std::cout << tmp1.bmem << std::endl;
    Bird tmp2;
    std::cout << tmp2.bmem << std::endl;
    tmp2 = tmp1;
    std::cout << tmp2.bmem << std::endl;
    return 0;
}
//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
//A lot of the code is taken from the textbook Thinking in C++ page 545 -547
//https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
//TA looked over code and output and said its good