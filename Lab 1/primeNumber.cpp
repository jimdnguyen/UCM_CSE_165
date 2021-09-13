#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int range = 10;
    int counter = 1;
    std::vector<int> primeNumbers;
    primeNumbers.push_back(1);
    //primeNumbers.push_back(2);

    for(int i = 1; i < range; i++)
    {   
       if(i % 2 != 0)
       {
           for(int j = i; j < primeNumbers.size(); j++)
           {
               if(j % 2 != 0)
               {
                   counter = counter + 1;
               }
               if(counter == primeNumbers.size()){
                   primeNumbers.push_back(j);
                   counter = 0;
               }
           }
       }
    }

    for(int z = 0; z < primeNumbers.size(); z++)
    {
        std::cout<<primeNumbers[z] << std::endl;
    }

    return 0;
}