#include <iostream>
#include <vector>
#include "StackOfInt.h"
#include "require.h"

#define n 5

class StackImpArray
{

};

class StackImpVector
{

};

int main()
{
    StackOfInt array;
    StackOfInt vector;
    array.initialize();
    vector.initialize();
    int arrstorage[n];
    std::vector<int> vecstorage;
    int* arrptr = &arrstorage[n];

    for(int i = 0; i < n; i++){
        arrstorage[i] = i + 1;
        vecstorage.push_back(i+1);

        array.push(arrstorage[i]);
        vector.push(vecstorage[i]);
    }

    array.peek();
    array.cleanup();

    std::cout<<std::endl;

    vector.peek();
    vector.cleanup();

    return 0;
}