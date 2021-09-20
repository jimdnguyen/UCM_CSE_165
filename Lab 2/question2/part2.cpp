#include <iostream>

void Fxn(void* sA, int nB, int value)
{
    int* restartingAddr = static_cast<int*> (sA);

    int* i;

    for(i = restartingAddr; i < restartingAddr + nB;i++)
    {
        *i = value;
    }
}

int main()
{
    int N = 10;

    int a[N] = {5, 510, 200, 2032, 123421, 32452, 234225, 213, 2125, 90};

    int numBytes = 5;

    int value = 10;

    void* startingAddr = static_cast<void*> (&a);

    //std::cout<<startingAddr<<std::endl;
    Fxn(startingAddr, numBytes, value);

    for(int i = 0; i < N; i++)
    {
        std::cout<<a[i]<<std::endl;
    }

    return 0;
}

// I mainly used the textbook page 182-185 to help me with this code