#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::string breakWord = "break";
    std::string inputWord;
    std::vector<int> inputNumber;
    int counter = 0;

    std::cin >> inputWord;
    inputNumber.push_back(counter);

    while(true)
    {   
        std::cin >> inputWord;
        inputNumber.push_back(counter);
        counter++;
        if(inputWord == breakWord)
        {
            break;
        }
        
    }
    //std::cout<<counter;

    for(int i = 1; i < inputNumber.size(); i++)
    {
        //std::cout<<inputNumber[i]<<std::endl;
        switch(inputNumber[i])
        {
            case 0: std::cout << "hi, i am a computer." << std::endl;
            break;

            case 1: std::cout << "bye, you left me alone." << std::endl;
            break;

            case 2: break;

            default: std::cout << "not any itneresting words found" << std::endl;
            break;
        }   
    }
    



    return 0;
}

// I used this website to see how to assign values to the string https://www.cplusplus.com/reference/string/string/assign/
