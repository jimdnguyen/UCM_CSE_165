#include <iostream>
#include <string>
#include <fstream>



int main()
{
    std::string breakWord = "quit";
    std::string inputWord;
    std::ifstream cppFile("inputWords.cpp");
    int caseNumber = 0;
    //the interesting words ill use will be #include , int , inputWord

    while(cppFile>> inputWord && inputWord != breakWord)
    {   
        //std::cout << inputWord << std::endl;
        if(inputWord == "#include")
        {
            caseNumber = 1;
        }
        else if(inputWord == "int")
        {
            caseNumber = 2;
        }
        else if(inputWord == "inputWord")
        {
            caseNumber = 3;
        }

        switch(caseNumber)
        {
            case 1: std::cout<<"Every header file needs a #include"<<std::endl; 
            break;

            case 2: std::cout<<"If you need to use numbers in c++, use an int"<<std::endl;
            break;

            case 3: std::cout<<"The variable used to compare each word is called inputWord"<<std::endl;
            break;
        }
        caseNumber = 0;
    }

    // quit
    // that is how i quit my while loop

    

    
}

// I used this website to see how to assign values to the string https://www.cplusplus.com/reference/string/string/assign/
// I used the textbook examples of using switches to help me write this code. The examples can be found in pg 134-136.
 
