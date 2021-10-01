#include <iostream>

class firstClass
{
    
    public:
        int sumF = 0;
        int tmpx = 15; // edit this value to change the value of x
        int *x = &tmpx;
        int addSum(int x, int* y)
        {
            sumF = x + *y;
            return sumF;
        }
};

class secondClass
{
    public:
        int sumS = 0;
        int tmpy = 25; // edit this value to change the value of y
        int *y = &tmpy;
        int addSum(int *x, int y)
        {
            sumS = *x + y;
            return sumS;
        }
};

int main()
{
    int x = 10;
    int y = 20;
    int sumS = 0;
    int sumF = 0;
    firstClass first;
    secondClass second;

    sumF = first.addSum(x,second.y);
    sumS = second.addSum(first.x,y);

    std::cout<< sumF << std::endl;
    std::cout<< sumS << std::endl;

    return 0;
}