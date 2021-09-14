#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int range = 1000;
    int counter = 0; 
    std::vector<int> primeNumbers;
    primeNumbers.push_back(2); //initialize the vector with the first prime number: 2 to calculate the rest of the prime numbers

    for(int i = 2; i < range; i++) // this for loop goes through the whole range to find all the prime numbers it can
    {   
       if(i % 2 != 0) // first, we get rid of all the even numbers since they can't be odd
       {
           for(int j = 0; j < primeNumbers.size(); j++) // then we iterate through our current list of prime numbers and see if the current number is divisible by any of them
           {
               
                if(i % primeNumbers[j] == 0) // if the current number is divisible by any primenumber inside the vector, we skip it since it isn't prime
                {
                   break;
                }
                else
                {
                    counter ++;
                }
            
                if(counter == primeNumbers.size()) // since the current number isn't divisible by any of them, we add it to the primenumber vector.
                {
                   primeNumbers.push_back(i);
                }
                
           }
           counter = 0;
            
       }
       
    }

    for(int z = 0; z < primeNumbers.size(); z++) // then we just print out all the prime numbers we found
    {
        std::cout<<primeNumbers[z] << std::endl;
    }
    

    return 0;
}