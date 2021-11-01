#include <iostream>

int i = 0;
int i2 = 1;
int tmpi = i;

void printFib(bool reset = false)
{

    if (reset == true)
    {
        i = 0;
        i2 = 1;
        tmpi = i;
    }
    else
    {
        tmpi = i;
        std::cout << i << std::endl;
        i = i + i2;
        i2 = tmpi;
    }
}

int main()
{
    printFib();
    printFib();
    printFib();
    printFib();
    printFib();
    printFib();
    printFib(true);
    printFib();
    printFib();
    printFib();

    return 0;
}

/*
https://www.mathsisfun.com/numbers/fibonacci-sequence.html
TA looked over my code and output and says its good
*/
