#include <iostream>

class X
{
public:
    X(int) {}
    X() {}
    virtual ~X() {}
    virtual void f()
    {
        std::cout << "X f()" << std::endl;
        return;
    }
};

class Y : public virtual X
{
public:
    Y(int) : X(1) {}
    Y() {}
    virtual void f()
    {
        std::cout << "Y f()" << std::endl;
        return;
    }
};

class Z : public virtual X
{
public:
    Z(int) : X(2) {}
    Z() {}
    virtual void f()
    {
        std::cout << "Z f()" << std::endl;
        return;
    }
};

class A : public Y, public Z
{
public:
    A() : Y(1), Z(1) {}
    void f()
    {
        std::cout << "A f()" << std::endl;
        return Y::f(), Z::f();
    }
};

int main()
{
    A obj;
    obj.f();

    return 0;
}
//https://www.tutorialspoint.com/return-from-void-functions-in-cplusplus
//I used the textbook Thinking in C++ 2nd edition pages 342 - 351
//TA looked over code/output and said its good