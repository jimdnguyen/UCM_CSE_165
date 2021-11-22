#include <iostream>
#include <cstring>
#include <fstream>

int main()
{
    std::string textObj;
    std::string returnASCII = "0x0d";
    std::fstream cppFile("part1.cpp");
    std::string inputWord;
    while (cppFile >> inputWord)
    {
        textObj = textObj + " " + inputWord;
    }
    int count = 0;
    int index = textObj.find(returnASCII, 0);

    while (index != std::string::npos)
    {
        count++;
        textObj.erase(index, returnASCII.size());
        index = textObj.find(returnASCII, index + 1);
    }

    //std::cout << count << std::endl;

    std::cout << textObj << std::endl;

    return 0;
}

//I wanted to find all the instances of the return ASCII value 0x0d and then delete 1 by 1, but then I realized that I can just delete as I find all the instances
//https://stackoverflow.com/questions/13565907/c-find-word-in-sentence
//TA said its okay after looking ~10 minutes.