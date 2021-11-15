#include <iostream>
//#include <exception>

class A
{
public:
    class X
    {
    public:
        static char *descX;
        X(char *tmp) { descX = tmp; };
    };
    class Y
    {
    public:
        static char *descY;
        Y(char *tmp) { descY = tmp; };
    };
    class Z
    {
    public:
        static char *descZ;
        Z(char *tmp) { descZ = tmp; };
    };
    void f() { throw Y("Y Just Got Thrown!"); }
};

char *A::X::descX = "X";
char *A::Y::descY = "Y";
char *A::Z::descZ = "Z";

int main()
{
    A obj;
    try
    {
        obj.f();
    }
    catch (A::X)
    {
        std::cout << "caught X" << std::endl;
        std::cout << A::X::descX << std::endl;
    }
    catch (A::Y)
    {
        std::cout << "caught Y" << std::endl;
        std::cout << A::Y::descY << std::endl;
    }
    catch (A::Z)
    {
        std::cout << "caught Z" << std::endl;
        std::cout << A::Z::descZ << std::endl;
    }
    return 0;
}
//I used the Thinking in C++ 2nd edition pages 388-390 to help me create this code
//TA looked over code/output and says it goods