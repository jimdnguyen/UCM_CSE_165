#include <iostream>

static int *ptrArray = 0;
int i = 1;

void printArray(int *array)
{
    ptrArray = array;
    std::cout << *ptrArray << std::endl;
}

void printArray()
{
    if (*(ptrArray + i) == -1)
    {
        std::cout << "End of Array" << std::endl;
    }
    else
    {
        std::cout << *(ptrArray + i) << std::endl;
        i += 1;
    }
}

int main()
{
    int array[6] = {1, 2, 3, 4, 5, -1};

    printArray(array);
    printArray();
    printArray();
    printArray();
    printArray();
    printArray();

    return 0;
}
//TA looked over my code and output and says its good